import javax.swing.*;
import java.awt.*;
import java.awt.print.PrinterGraphics;
import java.text.DecimalFormat;

public class Main
{
    public static JFrame frame;
    public static CheckingAccount account;
    public static DecimalFormat dollarFmt;

    public static void main(String[] args)
    {
        account = new CheckingAccount(getName(), getInitBalance());
        dollarFmt = new DecimalFormat("#0.00");

        frame = new JFrame("Options");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        EOptionsPanel panel = new EOptionsPanel();
        frame.getContentPane().add(panel);

        frame.pack();
        frame.setVisible(true);
    }

    public static void EnterTransaction()
    {
        int tCode;
        double tAmt;

        tCode = getTransCode();

        switch (tCode)
        {
            case 1:
                int checkNum = inputCheckNum();
                tAmt = getTransAmt();
                processCheck(tAmt, checkNum);
                break;
            case 2:
                double cash;
                double check;
                JPanel panel = new JPanel(new GridLayout(4, 1));
                JTextField cashInput = new JTextField(10);
                JTextField checkInput = new JTextField(10);
                panel.add(new JLabel("Cash"));
                panel.add(cashInput);
                panel.add(new JLabel("Checks"));
                panel.add(checkInput);
                JOptionPane.showConfirmDialog(null, panel, "Deposit Window", JOptionPane.OK_CANCEL_OPTION);

                if (cashInput.getText().isEmpty())
                    cash = 0;
                else
                    cash = Double.parseDouble(cashInput.getText());

                if (checkInput.getText().isEmpty())
                    check = 0;
                else
                    check = Double.parseDouble(checkInput.getText());

                processDeposit(cash, check);
                break;
            case 0:
                processEnd();
                break;
        }
    }

    public static void listAllTransactions()
    {
        String msg = "List All Transactions\nName: " + account.getName() + "\n\n";
        msg += String.format("%-7s", "ID");
        msg += String.format("%-15s", "Type");
        msg += String.format("%-7s", "Amount") + "\n";

        for (int i = 0 ; i < account.getTransCount() ; i++)
        {
            msg += String.format("%-" + (8 - String.valueOf(account.getTrans(i).getTransNumber()).length()) + "s", account.getTrans(i).getTransNumber()) +
                   transTypeString(account.getTrans(i).getTransId()) +
                   "$" + dollarFmt.format(account.getTrans(i).getTransAmt()) + "\n";
        }

        JOptionPane.showMessageDialog(null, msg);
    }

    public static void listAllChecks()
    {
        String msg = "List All Checks\n" +
                     "Name: " + account.getName() + "\n\n" +
                     "ID     Check     Amount\n";
        for (int i = 0 ; i < account.getTransCount() ; i++)
        {
            if (account.getTrans(i).getTransId() == 1)
                msg += String.format("%-" + (8 - String.valueOf(account.getTrans(i).getTransNumber()).length()) + "s", account.getTrans(i).getTransNumber()) +
                        String.format("%-" + (17 - String.valueOf(((Check)account.getTrans(i)).getCheckNumber()).length()) + "s", ((Check)account.getTrans(i)).getCheckNumber()) +
                        "$" + dollarFmt.format(account.getTrans(i).getTransAmt()) + "\n";
        }

        JOptionPane.showMessageDialog(null, msg);
    }

    public static void listAllDeposits()
    {
        String msg = "List All Deposits\n" +
                     "Name: " + account.getName() + "\n\n" +
                     "ID       Cash       Check       Amount\n";

        for (int i = 0 ; i < account.getTransCount() ; i++)
        {
            if (account.getTrans(i).getTransId() == 2)
                msg += String.format("%-" + (10 - String.valueOf((account.getTrans(i)).getTransNumber()).length()) + "s", account.getTrans(i).getTransNumber()) +
                        String.format("%-" + (15 - String.valueOf(((Deposit)account.getTrans(i)).getCash()).length()) + "s", "$" + dollarFmt.format(((Deposit)account.getTrans(i)).getCash())) +
                        String.format("%-" + (16 - String.valueOf(((Deposit)account.getTrans(i)).getCheck()).length()) + "s", "$" + dollarFmt.format(((Deposit)account.getTrans(i)).getCheck())) +
                        "$" + dollarFmt.format(account.getTrans(i).getTransAmt()) + "\n";
        }

        JOptionPane.showMessageDialog(null, msg);
    }

    public static String getName()
    {
        return JOptionPane.showInputDialog("Enter the account name: ");
    }

    public static double getInitBalance()
    {
        String input = JOptionPane.showInputDialog("Enter your initial balance: ");
        return Double.parseDouble(input);
    }

    public static int getTransCode()
    {
        String input = JOptionPane.showInputDialog("Transaction code: ");
        return Integer.parseInt(input);
    }

    public static double getTransAmt()
    {
        String input = JOptionPane.showInputDialog("Transaction amount: ");
        return Double.parseDouble(input);
    }

    public static int inputCheckNum()
    {
        String input = JOptionPane.showInputDialog("Enter your check number: ");
        return Integer.parseInt(input);
    }

    public static void processCheck(double amount, int checkNumber)
    {
        Check check = new Check(account.getTransCount(), 1, amount, checkNumber);
        account.addTrans(check);
        Transaction charge = new Transaction(account.getTransCount(), 3, 0.15);
        account.addTrans(charge);

        account.setBalance(amount, 1);

        String msg = account.getName() + "'s Account\n" +
                     "Transaction: Check #" + check.getCheckNumber() + " in Amount of $" + dollarFmt.format(amount) + "\n" +
                     "Current Balance: " + balanceString(false) + "\n" +
                     "Service Charge: Check --- charge $0.15\n";

        if ((account.getBalance() < 500) && !account.getBelowFiveHundredCharge())
        {
            Transaction chg = new Transaction(account.getTransCount(), 3, 5);
            account.addTrans(chg);
            account.setBelowFiveHundredCharge(true);
            msg += "Service Charge: Below $500 --- charge $5.00" + "\n";
        }

        if (account.getBalance() < 50)
        {
            msg += "Warning: Balance below $50" + "\n";
        }

        if (account.getBalance() < 0)
        {
            Transaction chg = new Transaction(account.getTransCount(), 3, 10);
            account.addTrans(chg);
            msg += "Service Charge: Below $0 --- charge $10.00\n";
        }

        msg += "Total Service Charge: $" + dollarFmt.format(account.getServiceCharge());

        JOptionPane.showMessageDialog(null, msg);
    }

    public static void processDeposit(double cash, double check)
    {
        Deposit deposit = new Deposit(account.getTransCount(), 2, cash, check);
        account.addTrans(deposit);
        Transaction charge = new Transaction(account.getTransCount(), 3, 0.10);
        account.addTrans(charge);

        account.setBalance(cash + check, 2);

        String msg = account.getName() + "'s Account\n" +
                     "Transaction: Deposit in Amount of $" + dollarFmt.format(cash + check) + "\n" +
                     "Current Balance: " + balanceString(false) + "\n" +
                     "Service Charge: Deposit --- charge $0.10\n";

        if (account.getBalance() < 50)
            msg += "Warning: Balance below $50\n";

        msg += "Total Service Charge: $" + dollarFmt.format(account.getServiceCharge());

        JOptionPane.showMessageDialog(null, msg);
    }

    public static void processEnd()
    {
        String msg = "Transaction: End\n" +
                     "Current Balance: " + balanceString(false) + "\n" +
                     "Total Service Charge: $" + account.getServiceCharge() + "\n" +
                     "Final Balance: " + balanceString(true);

        JOptionPane.showMessageDialog(null, msg);
    }

    public static String transTypeString(int id)
    {
        String str;
        if (id == 1)
            str = "Check       ";
        else if (id == 2)
            str = "Deposit    ";
        else
            str = "Svc. Chg.  ";

        return str;
    }

    public static String balanceString(boolean finalBalance)
    {
        String balanceStr;
        double balance;

        if (!finalBalance)
            balance = account.getBalance();
        else
            balance = account.getBalance() - account.getServiceCharge();

        if (balance < 0)
            balanceStr = "($" + dollarFmt.format(Math.abs(balance)) + ")";
        else
            balanceStr = "$" + dollarFmt.format(Math.abs(balance));

        return balanceStr;
    }
}
