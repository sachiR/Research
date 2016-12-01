import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Scanner;

import javax.swing.*;

import com.fazecast.jSerialComm.SerialPort;

/**
 * Created by Sachi on 30/11/2016.
 */

public class ModifiedSensorGraph {
	static SerialPort chosenPort; 
	static int x = 0;
	
	//defining JFrames, JPanels, JLabels, and variables
	JFrame window = new JFrame();
	Container con = window.getContentPane();
	JPanel northPanel = new JPanel();
	JPanel centrePanel = new JPanel();
	//JPanel southPanel = new JPanel();
	JComboBox<String> portList = new JComboBox<String>();
	JButton connectButton = new JButton("Connect");	
	
	JLabel titleLbl = new JLabel("Heart Rate Monitor");
	
	Color mainColour = new Color(201,229,232);
	Font mainFont = new Font("Serif", Font.BOLD, 40);
	
	
	public ModifiedSensorGraph(){
		//create and configure the window
		window.setTitle("Heart Rate Monitor System");
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.setSize(900, 600);
		window.setVisible(true);
		
		con.setBackground(mainColour);
		con.setLayout(new BorderLayout());
		
		//print the Heading
		headingPrint();
	}

	private void headingPrint() {
		con.add(northPanel, BorderLayout.NORTH);
		northPanel.setLayout(new FlowLayout());
		northPanel.setBackground(mainColour);
		titleLbl.setFont(mainFont);
		
		northPanel.add(titleLbl);
		
		//connecting to the port
		portConnector();
	}


	private void portConnector() {
		centrePanel.setLayout(new FlowLayout());
		centrePanel.setBackground(mainColour);
		
		window.add(centrePanel, BorderLayout.CENTER);
		
		//populate the drop-down box
		SerialPort[] portNames = SerialPort.getCommPorts();
		for(int i =0; i < portNames.length; i++){
			portList.addItem(portNames[i].getSystemPortName());
		}
		
		centrePanel.add(portList);
		
	}

	public static void main(String[] args ){
		new ModifiedSensorGraph();
	}
}



