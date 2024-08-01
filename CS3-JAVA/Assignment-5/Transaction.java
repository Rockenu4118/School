import java.io.Serializable;

public class Transaction implements Serializable
{
    private int transNumber;
    private int transId;
    private double transAmt;

    public Transaction(int number, int id, double amount)
    {
        transNumber = number;
        transId = id;
        transAmt = amount;
    }

    public int getTransNumber()
    {
        return transNumber;
    }

    public int getTransId()
    {
        return transId;
    }

    public double getTransAmt()
    {
        return transAmt;
    }
}
