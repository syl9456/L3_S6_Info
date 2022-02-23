package tp2;

public class DeuxThreads extends Thread{
    
    public void run() {
        this.setName("Bleu");
        for(int i = 0; i < 1000; i++ ) {
            System.out.println(this.getName() + " Nouveau thread");
            Wait(200);
        }
    }
    
    public static void main(String[] args) {
        DeuxThreads tt = new DeuxThreads();
        tt.setName("Gris");
        tt.start();
            
        
        for ( int i = 0; i < 1000; i++ ) {
            System.out.println(tt.getName() + " Thread principale");
            Wait(200);
        }
    }
    
    static void Wait(long milli) {  // C'est long mais on fait une pause de 200ms toutes les iterations
        System.out.println("pause de "+milli+" ms") ;
        try { 
            Thread.sleep(milli);
        }catch(InterruptedException x) {
            
        }
    }
    
    
}
