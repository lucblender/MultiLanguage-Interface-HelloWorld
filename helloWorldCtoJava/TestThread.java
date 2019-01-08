import static java.lang.Thread.sleep;

public class TestThread extends Thread{
	public TestThread(String name){
		super(name);
	}
	
	public void run(){
		for(int i = 0; i<11; i++)
		{
			System.out.println("\nThread: "+ this.getName()+" "+String.valueOf(10-i));

			try{
				sleep(1000);
			} catch(Exception e){
				e.printStackTrace();
			}
		}	
	}
}