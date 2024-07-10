import javax.swing.*;
import java.text.DecimalFormat;

public class Main
{
    public static JFrame frame;
    public static CheckingAccount account;
    public static DecimalFormat dollarFmt;

    public static void main(String[] args)
    {
        account = new CheckingAccount(getInitBalance());
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
                tAmt = getTransAmt();
                processCheck(tAmt);
                break;
            case 2:
                tAmt = getTransAmt();
                processDeposit(tAmt);
                break;
            case 0:
                processEnd();
                break;
        }
    }

    public static void listAllTransactions()
    {
        String msg = "List All Transactions\n\n";
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
        String msg = "List All Checks\n\nID     Amount\n";

        for (int i = 0 ; i < account.getTransCount() ; i++)
        {
            if (account.getTrans(i).getTransId() == 1)
                msg += String.format("%-" + (8 - String.valueOf(account.getTrans(i).getTransNumber()).length()) + "s", account.getTrans(i).getTransNumber()) +
                        "$" + dollarFmt.format(account.getTrans(i).getTransAmt()) + "\n";
        }

        JOptionPane.showMessageDialog(null, msg);
    }

    public static void listAllDeposits()
    {
        String msg = "List All Deposits\n\nID     Amount\n";

        for (int i = 0 ; i < account.getTransCount() ; i++)
        {
            if (account.getTrans(i).getTransId() == 2)
                msg += String.format("%-" + (8 - String.valueOf(account.getTrans(i).getTransNumber()).length()) + "s", account.getTrans(i).getTransNumber()) +
                        "$" + dollarFmt.format(account.getTrans(i).getTransAmt()) + "\n";
        }

        JOptionPane.showMessageDialog(null, msg);
    }

    public static double getInitBalance()
    {
        String input = JOptionPane.showInputDialog("Initial balance: ");
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

    public static void processCheck(double amount)
    {
        Transaction tx = new Transaction(account.getTransCount(), 1, amount);
        account.addTrans(tx);
        Transaction charge = new Transaction(account.getTransCount(), 3, 0.15);
        account.addTrans(charge);

        account.setBalance(amount, 1);

        String msg = "Transaction: Check in Amount of $" + dollarFmt.format(amount) + "\n" +
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

    public static void processDeposit(double amount)
    {
        Transaction tx = new Transaction(account.getTransCount(), 2, amount);
        account.addTrans(tx);
        Transaction charge = new Transaction(account.getTransCount(), 3, 0.10);
        account.addTrans(charge);

        account.setBalance(amount, 2);

        String msg = "Transaction: Deposit in Amount of $" + dollarFmt.format(amount) + "\n" +
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
