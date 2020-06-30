package study;

import javax.swing.JOptionPane;

public class Slime {
	String name;
	int hp = 80;
	int dmg = 10;
	
	public Slime(String s) {
		name = s;
	}
	
	public void attack(Human p) {
		
		if(hp > 0) {
			System.out.println(name + "는 " + p.name + "을 공격했다");
			p.hp -= dmg;
			
			if(p.hp < 1) {
				JOptionPane.showMessageDialog(null, "Game Over");
				System.exit(0);
			}
			
			System.out.println("현재 " + p.name + "의 체력은 " + p.hp + "이다\n");
		}		
	}
	
}