import java.text.SimpleDateFormat;
import java.text.DecimalFormat;
import java.util.Calendar;
import java.util.Random;

class Device2 extends Thread {
    Device2(String DeviceType) {
        setName(DeviceType);
        start();
    }
    String signalType;
    DecimalFormat df2 = new DecimalFormat("###.######");
    Calendar cal = Calendar.getInstance();
    SimpleDateFormat unitFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    Random rand = new Random();
    double sensory = rand.nextFloat();
  
    public void run() {
        try {
            for (int i = 1; i <= 9; i += 1) {
                Thread.sleep(1000);                  
                if (getName() == "Temperat") {
                    signalType = "Measurement: "+ df2.format(sensory*10)+"-°C";
                }
                if (getName() == "Pressure") {
                    signalType = "Measurement: "+df2.format(sensory*10)+"-kPa";
                }
                if (getName() == "PowerLev") {
                    signalType = "Measurement: "+ df2.format(sensory*10)+"-Wat";
                }
                System.out.println(getName() +"| MessageTypeCounter :"+ i + " | Time-Stamp : " + 
                unitFormat.format(cal.getTime())+" | "+signalType);
            }
        } catch (InterruptedException ie) {
            System.out.println(getName() + "has been Interrupted");
        }
      
        System.out.println("Transmittion is haulting  for " + getName() + " Device");
   }
}
