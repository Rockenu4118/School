import javax.swing.*;
import java.text.DecimalFormat;

public class Main
{
    public static CheckingAccount account;
    public static DecimalFormat dollarFmt;

    public static void main(String[] args)
    {
        account = new CheckingAccount(getInitBalance());
        dollarFmt = new DecimalFormat("#0.00");
        int tCode;
        double tAmt;

        do {
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
            }
        } while (tCode != 0);

        processEnd();
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
        account.setBalance(amount, 1);

        String msg = "Transaction: Check in Amount of $" + dollarFmt.format(amount) + "\n" +
                     "Current Balance: " + balanceString(false) + "\n" +
                     "Service Charge: Check --- charge $0.15\n";

        if ((account.getBalance() < 500) && !account.getBelowFiveHundredCharge())
        {
            account.setBelowFiveHundredCharge(true);
            msg += "Service Charge: Below $500 --- charge $5.00" + "\n";
        }

        if (account.getBalance() < 50)
            msg += "Warning: Balance below $50" + "\n";

        if (account.getBalance() < 0)
            msg += "Service Charge: Below $0 --- charge $10.00\n";

        msg += "Total Service Charge: $" + dollarFmt.format(account.getServiceCharge());

        JOptionPane.showMessageDialog(null, msg);
    }

    public static void processDeposit(double amount)
    {
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
