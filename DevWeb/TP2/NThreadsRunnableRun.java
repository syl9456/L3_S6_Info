package tp2;

public class NThreadsRunnableRun implements Runnable {
    
    public void run() {
        int i = 0;
        int random;
        while(i != 10) {
            i++;
            random = (int)(Math.random() * (1000+1));
            System.out.println("tictac " + Thread.currentThread().getName() +" : "+ i);
            Wait(random);
        }
        System.out.println();
        System.out.println(Thread.currentThread().getName() +" A FINI !  : "+ i);
        System.out.println();
    }
    
    
    static void Wait(long milli) {  // C'est long mais on fait une pause de 200ms toutes les iterations
        System.out.println("pause de "+milli+" ms") ;
        try { 
            Thread.sleep(milli);
        }catch(InterruptedException x) {
            
        }
    }

}
