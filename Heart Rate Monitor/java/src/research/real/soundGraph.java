import javax.sound.sampled.AudioFormat;
import javax.swing.*;
import java.awt.*;

/**
 * Created by Sachi on 4/12/2016.
 */
public class soundGraph extends JFrame{

    public soundGraph(){
        setSize(900,600);
        setVisible(true);
        getContentPane().setBackground(new Color(5, 22, 18));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        soundCapture();
    }

    private void soundCapture() {
        //AudioFormat format = new AudioFormat();
    }

    public static void main(String[] args) {
        JFrame frame = new soundGraph();
    }
}

