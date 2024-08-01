public class Deposit extends Transaction
{
    private double cash;
    private double check;

    public Deposit(int tCount, int tId, double cash, double check)
    {
        super(tCount, tId, cash + check);
        this.cash = cash;
        this.check = check;
    }

    public double getCash()
    {
        return cash;
    }

    public double getCheck()
    {
        return check;
    }
}
