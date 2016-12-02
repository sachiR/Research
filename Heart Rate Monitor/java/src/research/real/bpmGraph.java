import javax.sound.sampled.*;
import javax.swing.*;
import java.awt.*;
import java.io.ByteArrayOutputStream;

/**
 * Created by Sachi on /2/12/2016.
 */
public class bpmGraph extends JFrame{


   public bpmGraph(){
       setSize(900,600);
       setVisible(true);
       getContentPane().setBackground(new Color(5, 22, 18));
       setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

       soundCapture();
   }

    private void soundCapture() {
        AudioFormat format = new AudioFormat(AudioFormat.Encoding.PCM_SIGNED, 10000, 16, 2, 4, 10000, false);
        try {
            DataLine.Info info = new DataLine.Info(SourceDataLine.class, format);
            final SourceDataLine sourceLine = (SourceDataLine) AudioSystem.getLine(info);
            sourceLine.open();

            info = new DataLine.Info(TargetDataLine.class, format);
            final TargetDataLine targetLine = (TargetDataLine) AudioSystem.getLine(info);
            targetLine.open();

            final ByteArrayOutputStream out = new ByteArrayOutputStream();

            Thread sourceThread = new Thread()
            {
                @Override public void run()
                {
                    sourceLine.start();
                    while(true)
                    {
                        byte[] audioSignalBytes;

                        sourceLine.write(out.toByteArray(),0,out.size());
                        System.out.println();

                    }
                }
            };

            Thread targetThread = new Thread()
            {
                @Override public void run()
                {
                    targetLine.start();
                    byte[] data = new byte[targetLine.getBufferSize()/5];
                    int readBytes;
                    while(true)
                    {
                        readBytes = targetLine.read(data, 0 , data.length);
                        out.write(data,0,readBytes);
                    }
                }
            };

            targetThread.start();
            System.out.println("Started Recording");
            Thread.sleep(1000);
            targetLine.stop();
            targetLine.close();

            System.out.println("Ended Recording");
            System.out.println("--------------------------");
            System.out.println("Started Play Back");

            sourceThread.start();
            Thread.sleep(1000);
            sourceLine.stop();
            sourceLine.close();
            System.out.println("Ended Play Back");
        }
        catch (LineUnavailableException e){
            e.printStackTrace();
        }

        catch (InterruptedException e){
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        JFrame frame = new bpmGraph();

    }
}

