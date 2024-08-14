import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainMenu extends JFrame
{
    private JMenuItem openFile;
    private JMenuItem saveFile;

    private JMenuItem newAccount;
    private JMenuItem listTransactions;
    private JMenuItem listChecks;
    private JMenuItem listDeposits;
    private JMenuItem listServiceCharges;
    private JMenuItem findAccount;
    private JMenuItem listAccounts;

    private JMenuItem enterTransaction;

    public MainMenu()
    {
        super("Bank");

        // Menus
        JMenu fileMenu        = new JMenu("File");
        JMenu accountMenu     = new JMenu("Accounts");
        JMenu transactionMenu = new JMenu("Transactions");

        // File Menu Items
        openFile = new JMenuItem("Open File");
        saveFile = new JMenuItem("Save File");

        // Account Menu Items
        newAccount         = new JMenuItem("Add New Account");
        listTransactions   = new JMenuItem("List All Transactions");
        listChecks         = new JMenuItem("List All Checks");
        listDeposits       = new JMenuItem("List All Deposits");
        listServiceCharges = new JMenuItem("List All Service Charges");
        findAccount        = new JMenuItem("Find An Account");
        listAccounts       = new JMenuItem("List All Accounts");

        // Transaction Menu Items
        enterTransaction = new JMenuItem("Enter Transaction");

        MainMenuListener listener = new MainMenuListener();

        // File Menu Listeners
        openFile.addActionListener(listener);
        saveFile.addActionListener(listener);

        // Account Menu Listeners
        newAccount.addActionListener(listener);
        listTransactions.addActionListener(listener);
        listChecks.addActionListener(listener);
        listDeposits.addActionListener(listener);
        listServiceCharges.addActionListener(listener);
        findAccount.addActionListener(listener);
        listAccounts.addActionListener(listener);

        // Transaction Menu Listeners
        enterTransaction.addActionListener(listener);

        fileMenu.add(openFile);
        fileMenu.add(saveFile);

        accountMenu.add(newAccount);
        accountMenu.add(listTransactions);
        accountMenu.add(listChecks);
        accountMenu.add(listDeposits);
        accountMenu.add(listServiceCharges);
        accountMenu.add(findAccount);
        accountMenu.add(listAccounts);

        transactionMenu.add(enterTransaction);

        JMenuBar bar = new JMenuBar();
        bar.add(fileMenu);
        bar.add(accountMenu);
        bar.add(transactionMenu);
        setJMenuBar(bar);

        setPreferredSize(new Dimension(400, 250));
    }

    private class MainMenuListener implements ActionListener
    {
        public void actionPerformed(ActionEvent event)
        {
            Object source = event.getSource();
            if (source == openFile)
                Main.readFile();
            else if (source == saveFile)
                Main.writeFile();
            else if (source == newAccount)
                Main.newAccount();
            else if (source == listTransactions)
                Main.listAllTransactions();
            else if (source == listChecks)
                Main.listAllChecks();
            else if (source == listDeposits)
                Main.listAllDeposits();
            else if (source == listServiceCharges)
                Main.listAllServiceCharges();
            else if (source == findAccount)
                Main.findAccount();
            else if (source == listAccounts)
                Main.listAccounts();
            else if (source == enterTransaction) {
                try
                {
                    Main.EnterTransaction();
                }
                catch (NumberFormatException e)
                {
                    System.out.println(e);
                }
            }
        }
    }
}
