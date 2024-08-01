import java.io.Serializable;
import java.util.ArrayList;

public class CheckingAccount extends Account implements Serializable
{
    private ArrayList<Transaction> transList;
    private int transCount;
    private double totalServiceCharge;
    private boolean belowFiveHundredCharge = false;

    public CheckingAccount(String name, double initialBalance)
    {
        super(name, initialBalance);
        transList = new ArrayList<Transaction>();
        totalServiceCharge = 0.0;
        transCount = 0;
    }

    public void addTrans(Transaction newTrans)
    {
        transList.add(newTrans);
        transCount++;
        Main.newChanges();
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
        Main.newChanges();
    }

    public double getServiceCharge()
    {
        return totalServiceCharge;
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