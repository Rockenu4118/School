import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class EOptionsPanel extends JPanel
{
    private JRadioButton a, b, c, d;

    public EOptionsPanel()
    {
        JLabel prompt = new JLabel("     Choose action:       ");
        prompt.setFont(new Font("Helvetica", Font.BOLD, 24));

        a = new JRadioButton("Enter Transaction");
        a.setBackground(Color.green);
        b = new JRadioButton("List All Transactions");
        b.setBackground(Color.green);
        c = new JRadioButton("List All Checks");
        c.setBackground(Color.green);
        d = new JRadioButton("List All Deposits");
        d.setBackground(Color.green);

        ButtonGroup group = new ButtonGroup();
        group.add(a);
        group.add(b);
        group.add(c);
        group.add(d);

        EOptionListener listener = new EOptionListener();
        a.addActionListener(listener);
        b.addActionListener(listener);
        c.addActionListener(listener);
        d.addActionListener(listener);

        add(prompt);
        add(a);
        add(b);
        add(c);
        add(d);

        setBackground(Color.green);
        setPreferredSize(new Dimension(300, 100));
    }

    private class EOptionListener implements ActionListener
    {
        public void actionPerformed(ActionEvent event)
        {
            Object source = event.getSource();
            if (source == a)
                Main.EnterTransaction();
            else if (source == b)
                Main.listAllTransactions();
            else if (source == c)
                Main.listAllChecks();
            else if (source == d)
                Main.listAllDeposits();
        }
    }
}
