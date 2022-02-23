package tp2;

public class NThreads extends Thread implements Runnable {
    
    public void run() {
        int i = 0;
        int random;
        while(i != 10) {
            i++;
            random = (int)(Math.random() * (1000+1));
            System.out.println("tictac " + this.getName() +" : "+ i);
            Wait(random);
        }
        System.out.println();
        System.out.println(this.getName() +" A FINI !  : "+ i);
        System.out.println();
    }
    
    
    public static void main(String[] args) {    
        int n = Integer.parseInt(args[0]);
        NThreads[] tabThreads = new NThreads[n];
        
        if( n > 10 ) {
            System.exit(0);
        }
            
        for(int i = 0; i<n; i++) {
            tabThreads[i] = new NThreads();
            tabThreads[i].setName("Thread "+i);    
            try {
                tabThreads[i].join();
            }
            catch(InterruptedException e) {
            }
            System.out.println(tabThreads[i].getName());
        }
        
        for(int i = 0; i<n; i++) {
            tabThreads[i].start();
        }
    }
    
    
    static void Wait(long milli) {  // On fait une pause de 200ms toutes les iterations
        System.out.println("pause de "+milli+" ms") ;
        try { 
            Thread.sleep(milli);
        }catch(InterruptedException x) {
            
        }
    }

}
