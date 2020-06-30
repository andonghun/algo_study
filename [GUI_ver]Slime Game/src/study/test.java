package study;

import java.util.Timer;
import java.util.TimerTask;

public class test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(1);
		
		Timer timer1 = new Timer();
		TimerTask task1 = new TimerTask() {
			
			@Override
			public void run() {
				System.out.println(2);
				timer1.cancel();
			}
		};
		
		timer1.schedule(task1, 3000);		
	}

}
