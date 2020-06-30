package study;

import java.util.Timer;
import java.util.TimerTask;

import javax.swing.ImageIcon;

public class Human {
	
	String name;
	int hp = 100;
	
	public Human(String n) {
		name = n;
	}
	
	public void attack(Slime s) {
		ImageIcon bsImg_crushed =
				new ImageIcon(Main.class.getResource("/study/img/slime2(blue).png"));
		ImageIcon rsImg_crushed =
				new ImageIcon(Main.class.getResource("/study/img/slime2(red).png"));
		
		if(s instanceof BlueSlime) {
			Main.imgLbl1.setIcon(bsImg_crushed);
		}
		else {
			Main.imgLbl2.setIcon(rsImg_crushed);
		}
		
		Timer timer1 = new Timer();
		Timer timer2 = new Timer();
		TimerTask task1 = new TimerTask() {
			
			@Override
			public void run() {
				Main.imgLbl1.setIcon(Main.bsImg);
				Main.imgLbl2.setIcon(Main.rsImg);
				timer1.cancel();
			}
		};
		
		TimerTask task2 = new TimerTask() {
			
			@Override
			public void run() {
				Main.lbl.setText("현재 " + s.name + "의 체력은 " + s.hp + "이다\n");
				timer2.cancel();
			}
		};
		
		timer1.schedule(task1, 500);
		
		int randomNum = (int) (Math.random() * 3);

		int check = 0;
		if(randomNum == 0) {
			s.hp = s.hp - 60; // 크리티컬
			Main.lbl.setText("신난다! 치명적인 공격!");
			timer2.schedule(task2, 500);
			check = 1;
		}
		
		else s.hp = s.hp - 30;
		
		if(s.hp < 1) {
			if(s == Main.bs) {
				Main.btn1.setEnabled(false);
			}
			else {
				Main.btn2.setEnabled(false);
			}
		}
		else {
			if(check == 0) Main.lbl.setText("현재 " + s.name + "의 체력은 " + s.hp + "이다\n");
		}
	}

}
