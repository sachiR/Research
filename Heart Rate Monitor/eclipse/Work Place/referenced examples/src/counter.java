public class counter {
	static Thread thread = new Thread();
	
	public static void main(String args[]) throws InterruptedException{
		while (true){
			for (int c = 10; c>=1; c--){
				thread.sleep(1000);
				System.out.println(c);
			}
		}
	}
}
