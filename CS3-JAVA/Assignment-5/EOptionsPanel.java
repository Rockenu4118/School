import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileNotFoundException;

public class EOptionsPanel extends JPanel
{
    private JRadioButton a, b, c, d, e, f;

    public EOptionsPanel()
    {
        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

        JLabel prompt = new JLabel("Choose action:");
        prompt.setFont(new Font("Helvetica", Font.BOLD, 24));
        prompt.setAlignmentX(CENTER_ALIGNMENT);

        a = new JRadioButton("Enter Transaction");
        a.setBackground(Color.green);
        b = new JRadioButton("List All Transactions");
        b.setBackground(Color.green);
        c = new JRadioButton("List All Checks");
        c.setBackground(Color.green);
        d = new JRadioButton("List All Deposits");
        d.setBackground(Color.green);
        e = new JRadioButton("Open File");
        e.setBackground(Color.green);
        f = new JRadioButton("Save File");
        f.setBackground(Color.green);

        EOptionListener listener = new EOptionListener();
        a.addActionListener(listener);
        b.addActionListener(listener);
        c.addActionListener(listener);
        d.addActionListener(listener);
        e.addActionListener(listener);
        f.addActionListener(listener);

        add(prompt);

        ButtonGroup group = new ButtonGroup();
        group.add(a);
        group.add(b);
        group.add(c);
        group.add(d);
        group.add(e);
        group.add(f);

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(a);
        buttonPanel.add(b);
        buttonPanel.add(c);
        buttonPanel.add(d);
        buttonPanel.add(e);
        buttonPanel.add(f);
        buttonPanel.setBackground(Color.green);
        buttonPanel.setLayout(new GridLayout(3, 2));

        add(buttonPanel);

        setBackground(Color.green);
        setPreferredSize(new Dimension(300, 150));
    }

    private class EOptionListener implements ActionListener
    {
        public void actionPerformed(ActionEvent event)
        {
            Object source = event.getSource();
            if (source == a)
                try
                {
                    Main.EnterTransaction();
                }
                catch (NumberFormatException e)
                {
                    System.out.println(e);
                }
            else if (source == b)
                Main.listAllTransactions();
            else if (source == c)
                Main.listAllChecks();
            else if (source == d)
                Main.listAllDeposits();
            else if (source == e)
                Main.readFile();
            else if (source == f) {
                Main.writeFile();
            }

        }
    }
}
