package study;

import javax.swing.JOptionPane;

public class Slime {
	String name;
	int hp = 800;
	
	public Slime(String s) {
		name = s;
	}
	
	public void attack(Human p) {
		attack(p, 10);
	}
	
	public void attack(Human p, int dmg) {
		
		if(hp > 0) {
			System.out.println(name + "는 " + p.name + "을 공격했다");
			p.hp -= dmg;
			
			if(p.hp < 1) {
				JOptionPane.showMessageDialog(null, "Game Over");
				System.exit(0);
			}
			
			if(dmg < 30) {
				Main.lbl2.setText(name + "의 공격 " + p.name + "의 체력은 " + p.hp + "이다\n");
			}
			else {
				Main.lbl2.setText(name + "의 강한 공격! " + p.name + "의 체력은 " + p.hp + "이다\n");
			}
		}		
	}
	
}

class BlueSlime extends Slime{
	
	public BlueSlime(String s) {
		super(s);
	}

	@Override
	public void attack (Human p) {
		attack(p, 8);
	}
	
	void heal(Slime s) {
		if(hp > 0 && s.hp > 0) {//블루 슬라임이 살아있고, 힐 받는 슬라임이 살아있으면
			s.hp += 10;
			
			if(s.hp > 80) {
				s.hp = 80;
			}
			
			Main.lbl2.setText(name + "는 " + s.name + "를 치료. 그의 체력은" + s.hp + ".");
		}
	}
	
}

class RedSlime extends Slime{
	public RedSlime(String s) {
		super(s);
	}
	
	@Override
	public void attack(Human p) {
		attack(p, 15);
	}
	
	public void attack2(Human p) {
		attack(p, 30);
	}
}