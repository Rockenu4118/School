import javax.swing.*;
import java.io.Serializable;
import java.util.Objects;
import java.util.Vector;

public class AccountManager implements Serializable
{
    private CheckingAccount currAcct = null;
    private Vector<CheckingAccount> accounts;

    public AccountManager()
    {
        accounts = new Vector<CheckingAccount>();
    }

    public int numAccounts() { return accounts.size(); }

    public CheckingAccount getAcct(int i) { return accounts.get(i); }

    public boolean setAcct(String name)
    {
        for (CheckingAccount acct : accounts)
        {
            if (acct.getName().equals(name))
            {
                currAcct = acct;
                return true;
            }
        }

        return false;
    }

    public void createAccount()
    {
        CheckingAccount newAcct = new CheckingAccount(getName(), getInitBalance());
        accounts.add(newAcct);
        currAcct = newAcct;
    }

    public CheckingAccount currAcct() { return currAcct; }

    private static String getName()
    {
        return JOptionPane.showInputDialog("Enter the account name: ");
    }

    private static double getInitBalance()
    {
        String input = JOptionPane.showInputDialog("Enter your initial balance: ");
        if (input.isEmpty())
            return 0.0;
        return Double.parseDouble(input);
    }
}
