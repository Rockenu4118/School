public class CheckingAccount
{
    private double balance;
    private double totalServiceCharge;
    private boolean belowFiveHundredCharge = false;

    public CheckingAccount(double initialBalance)
    {
        balance = initialBalance;
        totalServiceCharge = 0.0;
    }

    public double getBalance()
    {
        return balance;
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