import java.util.ArrayList;

public class CheckingAccount
{
    private ArrayList<Transaction> transList;
    private int transCount;
    private double balance;
    private double totalServiceCharge;
    private boolean belowFiveHundredCharge = false;

    public CheckingAccount(double initialBalance)
    {
        transList = new ArrayList<Transaction>();
        balance = initialBalance;
        totalServiceCharge = 0.0;
        transCount = 0;
    }

    public double getBalance()
    {
        return balance;
    }

    public void addTrans(Transaction newTrans)
    {
        transList.add(newTrans);
        transCount++;
    }

    public int getTransCount()
    {
        return transCount;
    }

    public Transaction getTrans(int i)
    {
        return transList.get(i);
    }

    public void setBalance(double transAmt, int tCode)
    {
        if (tCode == 1)
        {
            balance = balance - transAmt;
            totalServiceCharge = totalServiceCharge + 0.15;

            if (balance < 500.0 && !belowFiveHundredCharge)
            {
                totalServiceCharge = totalServiceCharge + 5;
            }
            if (balance < 0)
            {
                totalServiceCharge = totalServiceCharge + 10;
            }
        }
        else if (tCode == 2)
        {
            balance = balance + transAmt;
            totalServiceCharge = totalServiceCharge + 0.1;
        }
    }

    public double getServiceCharge()
    {
        return totalServiceCharge;
    }

    public void setServiceCharge(double currentServiceCharge)
    {
        totalServiceCharge = currentServiceCharge;
    }

    public boolean getBelowFiveHundredCharge()
    {
        return belowFiveHundredCharge;
    }

    public void setBelowFiveHundredCharge(boolean val)
    {
        belowFiveHundredCharge = val;
    }

}