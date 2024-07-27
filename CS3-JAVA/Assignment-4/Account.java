public class Account
{
    protected String name;
    protected double balance;

    public Account(String acctName, double initBalance)
    {
        name    = acctName;
        balance = initBalance;
    }

    public String getName()
    {
        return name;
    }

    public double getBalance()
    {
        return balance;
    }

    public void setBalance(double balance)
    {
        this.balance = balance;
    }
}
