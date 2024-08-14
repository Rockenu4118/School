import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.text.DecimalFormat;

public class Main
{
    public static JFrame frame;
    public static JTextArea text;
    public static AccountManager accountManager;
    public static DecimalFormat dollarFmt;

    public static void main(String[] args)
    {
        accountManager = new AccountManager();
        dollarFmt = new DecimalFormat("#0.00");

        frame = new MainMenu();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        text = new JTextArea();
        frame.add(text);

        frame.pack();
        frame.setVisible(true);

        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                saveNewChanges();
            }
        });
    }

    public static void updateScreen(String msg) { text.setText(msg); }

    public static void EnterTransaction() throws NumberFormatException
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

        updateScreen("");
    }

    public static void listAllTransactions()
    {
        if (accountManager.currAcct() == null)
        {
            JOptionPane.showMessageDialog(null, "You must select an account first.");
            return;
        }

        String msg = "List All Transactions\n";
        msg += "Name: " + accountManager.currAcct().getName() + "\n";
        msg += "Balance: " + balanceString(false) + "\n";
        msg += "Total Service Charge: $" + accountManager.currAcct().getServiceCharge() + "\n\n";
        msg += String.format("%-8s", "ID");
        msg += String.format("%-15s", "Type");
        msg += String.format("%-7s", "Amount") + "\n";

        for (int i = 0 ; i < accountManager.currAcct().getTransCount() ; i++)
        {
            msg += String.format("%-" + (10 - String.valueOf(accountManager.currAcct().getTrans(i).getTransNumber()).length()) + "s", accountManager.currAcct().getTrans(i).getTransNumber()) +
                   transTypeString(accountManager.currAcct().getTrans(i).getTransId()) +
                   "$" + dollarFmt.format(accountManager.currAcct().getTrans(i).getTransAmt()) + "\n";
        }

        updateScreen(msg);
    }

    public static void listAllChecks()
    {
        if (accountManager.currAcct() == null)
        {
            JOptionPane.showMessageDialog(null, "You must select an account first.");
            return;
        }

        String msg = "List All Checks\n";
        msg += "Name: " + accountManager.currAcct().getName() + "\n";
        msg += "Balance: " + balanceString(false) + "\n";
        msg += "Total Service Charge: $" + accountManager.currAcct().getServiceCharge() + "\n\n";
        msg += "ID     Check     Amount\n";
        for (int i = 0 ; i < accountManager.currAcct().getTransCount() ; i++)
        {
            if (accountManager.currAcct().getTrans(i).getTransId() == 1)
                msg += String.format("%-" + (8 - String.valueOf(accountManager.currAcct().getTrans(i).getTransNumber()).length()) + "s", accountManager.currAcct().getTrans(i).getTransNumber()) +
                        String.format("%-" + (17 - String.valueOf(((Check)accountManager.currAcct().getTrans(i)).getCheckNumber()).length()) + "s", ((Check)accountManager.currAcct().getTrans(i)).getCheckNumber()) +
                        "$" + dollarFmt.format(accountManager.currAcct().getTrans(i).getTransAmt()) + "\n";
        }

        updateScreen(msg);
    }

    public static void listAllDeposits()
    {
        if (accountManager.currAcct() == null)
        {
            JOptionPane.showMessageDialog(null, "You must select an account first.");
            return;
        }

        String msg = "List All Deposits\n";
        msg += "Name: " + accountManager.currAcct().getName() + "\n";
        msg += "Balance: " + balanceString(false) + "\n";
        msg += "Total Service Charge: $" + accountManager.currAcct().getServiceCharge() + "\n\n";
        msg += "ID       Cash       Check       Amount\n";

        for (int i = 0; i < accountManager.currAcct().getTransCount(); i++) {
            if (accountManager.currAcct().getTrans(i).getTransId() == 2)
                msg += String.format("%-" + (10 - String.valueOf((accountManager.currAcct().getTrans(i)).getTransNumber()).length()) + "s", accountManager.currAcct().getTrans(i).getTransNumber()) +
                        String.format("%-" + (15 - String.valueOf(((Deposit) accountManager.currAcct().getTrans(i)).getCash()).length()) + "s", "$" + dollarFmt.format(((Deposit) accountManager.currAcct().getTrans(i)).getCash())) +
                        String.format("%-" + (16 - String.valueOf(((Deposit) accountManager.currAcct().getTrans(i)).getCheck()).length()) + "s", "$" + dollarFmt.format(((Deposit) accountManager.currAcct().getTrans(i)).getCheck())) +
                        "$" + dollarFmt.format(accountManager.currAcct().getTrans(i).getTransAmt()) + "\n";
        }

        updateScreen(msg);
    }

    public static void listAllServiceCharges()
    {
        if (accountManager.currAcct() == null)
        {
            JOptionPane.showMessageDialog(null, "You must select an account first.");
            return;
        }

        String msg = "List All Service Charges\n";
        msg += "Name: " + accountManager.currAcct().getName() + "\n";
        msg += "Balance: " + balanceString(false) + "\n";
        msg += "Total Service Charge: " + accountManager.currAcct().getServiceCharge() + "\n\n";
        msg += "ID       Amount\n";

        for (int i = 0 ; i < accountManager.currAcct().getTransCount() ; i++)
        {
            if (accountManager.currAcct().getTrans(i).getTransId() == 3)
            {
                msg += String.format("%-" + (10 - String.valueOf((accountManager.currAcct().getTrans(i)).getTransNumber()).length()) + "s", accountManager.currAcct().getTrans(i).getTransNumber());
                msg += "$" + dollarFmt.format(accountManager.currAcct().getTrans(i).getTransAmt()) + "\n";
            }
        }

        updateScreen(msg);
    }

    public static void findAccount()
    {
        String name = JOptionPane.showInputDialog("Enter the account name: ");

        if (accountManager.setAcct(name))
            updateScreen("Found account for " + name);
        else
            updateScreen("Account not found for " + name);
    }

    public static void listAccounts()
    {
        String msg = "List of All Accounts:\n\n";

        for (int i = 0 ; i < accountManager.numAccounts() ; i++)
        {
            msg += "Name: " + accountManager.getAcct(i).getName() + "\n";
            msg += "Balance: " + balanceString(false) + "\n";
            msg += "Total Service Charge: $" + accountManager.getAcct(i).getServiceCharge() + "\n\n";
        }

        updateScreen(msg);
    }

    public static void newAccount()
    {
        accountManager.createAccount();
        updateScreen("New account added for " + accountManager.currAcct().getName());
    }

    public static void saveNewChanges()
    {
        if (Storage.needToSave())
        {
            String msg = "The data in the application is not saved.\nWould you like to save it before exiting the application?";

            if (JOptionPane.showConfirmDialog(null, msg) == JOptionPane.YES_OPTION)
                writeFile();
        }
    }

    public static void readFile()
    {
        saveNewChanges();

        Storage.fileToRead();

        try {
            FileInputStream fis = new FileInputStream(Storage.getFilename());
            BufferedInputStream bis = new BufferedInputStream(fis);
            ObjectInputStream in = new ObjectInputStream(bis);

            accountManager = (AccountManager) in.readObject();

            Storage.resetNewChanges();
        } catch (IOException e) {
            System.out.println(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public static void writeFile()
    {
        Storage.fileToWrite();

        try
        {
            FileOutputStream fos = new FileOutputStream(Storage.getFilename());
            BufferedOutputStream bos = new BufferedOutputStream(fos);
            ObjectOutputStream oos = new ObjectOutputStream(bos);
            oos.writeObject(accountManager);
            oos.close();
            Storage.resetNewChanges();
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public static int getTransCode()
    {
        String input = JOptionPane.showInputDialog("Enter your transaction code: ");
        return Integer.parseInt(input);
    }

    public static double getTransAmt()
    {
        String input = JOptionPane.showInputDialog("Enter your check amount: ");
        return Double.parseDouble(input);
    }

    public static int inputCheckNum()
    {
        String input = JOptionPane.showInputDialog("Enter your check number: ");
        return Integer.parseInt(input);
    }

    public static void processCheck(double amount, int checkNumber)
    {
        Check check = new Check(accountManager.currAcct().getTransCount(), 1, amount, checkNumber);
        accountManager.currAcct().addTrans(check);
        Transaction charge = new Transaction(accountManager.currAcct().getTransCount(), 3, 0.15);
        accountManager.currAcct().addTrans(charge);

        accountManager.currAcct().setBalance(amount, 1);

        String msg = accountManager.currAcct().getName() + "'s Account\n" +
                     "Transaction: Check #" + check.getCheckNumber() + " in Amount of $" + dollarFmt.format(amount) + "\n" +
                     "Current Balance: " + balanceString(false) + "\n" +
                     "Service Charge: Check --- charge $0.15\n";

        if ((accountManager.currAcct().getBalance() < 500) && !accountManager.currAcct().getBelowFiveHundredCharge())
        {
            Transaction chg = new Transaction(accountManager.currAcct().getTransCount(), 3, 5);
            accountManager.currAcct().addTrans(chg);
            accountManager.currAcct().setBelowFiveHundredCharge(true);
            msg += "Service Charge: Below $500 --- charge $5.00" + "\n";
        }

        if (accountManager.currAcct().getBalance() < 50)
        {
            msg += "Warning: Balance below $50" + "\n";
        }

        if (accountManager.currAcct().getBalance() < 0)
        {
            Transaction chg = new Transaction(accountManager.currAcct().getTransCount(), 3, 10);
            accountManager.currAcct().addTrans(chg);
            msg += "Service Charge: Below $0 --- charge $10.00\n";
        }

        msg += "Total Service Charge: $" + dollarFmt.format(accountManager.currAcct().getServiceCharge());

        JOptionPane.showMessageDialog(null, msg);
    }

    public static void processDeposit(double cash, double check)
    {
        Deposit deposit = new Deposit(accountManager.currAcct().getTransCount(), 2, cash, check);
        accountManager.currAcct().addTrans(deposit);
        Transaction charge = new Transaction(accountManager.currAcct().getTransCount(), 3, 0.10);
        accountManager.currAcct().addTrans(charge);

        accountManager.currAcct().setBalance(cash + check, 2);

        String msg = accountManager.currAcct().getName() + "'s Account\n" +
                     "Transaction: Deposit in Amount of $" + dollarFmt.format(cash + check) + "\n" +
                     "Current Balance: " + balanceString(false) + "\n" +
                     "Service Charge: Deposit --- charge $0.10\n";

        if (accountManager.currAcct().getBalance() < 50)
            msg += "Warning: Balance below $50\n";

        msg += "Total Service Charge: $" + dollarFmt.format(accountManager.currAcct().getServiceCharge());

        JOptionPane.showMessageDialog(null, msg);
    }

    public static void processEnd()
    {
        String msg = "Transaction: End\n" +
                     "Current Balance: " + balanceString(false) + "\n" +
                     "Total Service Charge: $" + accountManager.currAcct().getServiceCharge() + "\n" +
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
            balance = accountManager.currAcct().getBalance();
        else
            balance = accountManager.currAcct().getBalance() - accountManager.currAcct().getServiceCharge();

        if (balance < 0)
            balanceStr = "($" + dollarFmt.format(Math.abs(balance)) + ")";
        else
            balanceStr = "$" + dollarFmt.format(Math.abs(balance));
//
        return balanceStr;
    }
}
