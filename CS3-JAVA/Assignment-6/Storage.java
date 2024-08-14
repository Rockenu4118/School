import javax.swing.*;
import java.io.File;

public class Storage
{
    public static String filename = "C:\\acct.dat";
    public static boolean newChanges = false;

    public Storage()
    {}

    public static String getFilename() { return filename; }

    public static void newChanges() { newChanges = true; }

    public static void resetNewChanges() { newChanges = false; }

    public static boolean needToSave() { return newChanges; }

    public static void fileToRead()
    {
        String msg = "Would you like to use the current default file: " + filename;

        int confirm = JOptionPane.showConfirmDialog(null, msg);

        if (confirm == JOptionPane.YES_OPTION)
            return;

        if (confirm == JOptionPane.CANCEL_OPTION)
            return;

        if (confirm == JOptionPane.CLOSED_OPTION)
            return;

        JFileChooser chooser = new JFileChooser();

        if (chooser.showOpenDialog(null) == JFileChooser.APPROVE_OPTION)
        {
            File file = chooser.getSelectedFile();
            filename = file.getPath();
        }
    }

    public static void fileToWrite()
    {
        String msg = "Would you like to use the current default file: " + filename;

        int confirm = JOptionPane.showConfirmDialog(null, msg);

        if (confirm == JOptionPane.YES_OPTION)
            return;

        if (confirm == JOptionPane.CANCEL_OPTION)
            return;

        if (confirm == JOptionPane.CLOSED_OPTION)
            return;

        JFileChooser chooser = new JFileChooser();

        if (chooser.showSaveDialog(null) == JFileChooser.APPROVE_OPTION)
        {
            File file = chooser.getSelectedFile();
            filename = file.getPath();
        }
    }
}
