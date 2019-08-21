public class Device1 {
    public static void main(String[] args) {
        Device2 D1 = new Device2("Temperat");
        Device2 D2 = new Device2("Pressure");
        Device2 D3 = new Device2("PowerLev");
        System.out.println("Device #1 is alive : " + D1.isAlive());
        System.out.println("Device #2 is alive : " + D2.isAlive());
        System.out.println("Device #3 is alive : " + D3.isAlive());
        try {//Cleanups
            D1.join();
            D2.join();
            D3.join();
        } catch (InterruptedException ie) {
            System.out.println("Device Controller is Interrupted");
        }
        System.out.println("Device #1 is alive : " + D1.isAlive());
        System.out.println("Device #2 is alive : " + D2.isAlive());
        System.out.println("Device #3 is alive : " + D3.isAlive());
        System.out.println("Exiting MainThread");
    }
}
