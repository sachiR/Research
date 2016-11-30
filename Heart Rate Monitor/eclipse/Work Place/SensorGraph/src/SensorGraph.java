import java.awt.BorderLayout;

import javax.swing.*;

import com.fazecast.jSerialComm.SerialPort;

/**
 * Created by Sachi on 29/11/2016.
 */

public class SensorGraph {

    public static void main(String[] args) {

        //create and configure the window
        JFrame window = new JFrame();
        window.setTitle("Sound Sensor Graph");
        window.setSize(900,700);
        window.setLayout(new BorderLayout());
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //create a drop-down box and connect button, then place them at the top of the window
        JComboBox<String> portList = new JComboBox<String>();
        JButton connectButton = new JButton("Connect");
        JPanel topPanel = new JPanel();
        topPanel.add(portList);
        topPanel.add(connectButton);
        window.add(topPanel, BorderLayout.NORTH);

        //populate the drop-down box
        SerialPort[] port
        
        //show the window
        window.setVisible(true);

    }

}
