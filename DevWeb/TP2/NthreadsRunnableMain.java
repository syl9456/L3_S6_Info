package tp2;

public class NthreadsRunnableMain {
    
    public static void main(String[] args) {    
        int n = Integer.parseInt(args[0]);
        Thread[] tabThreads = new Thread[n];
        
        if( n > 10 ) {
            System.exit(0);
        }
            
        for(int i = 0; i<n; i++) {
            tabThreads[i] = new Thread(new NThreadsRunnableRun());
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

}
