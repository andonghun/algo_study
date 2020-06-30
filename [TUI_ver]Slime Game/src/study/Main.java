package study;

import javax.swing.JOptionPane;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Slime s = null; // 빈 슬라임 변수

		Slime s1 = new Slime("파이어 슬라임");
		Slime s2 = new Slime("지옥 슬라임");
		Human p = new Human("용사");
		
		System.
		out.
		println(s1.name + "와 " + s2.name + "이 나타났다! 당신의 이름은 " + p.name + "이다\n");

		while(true) {
			
			String sel = JOptionPane.showInputDialog("어느 슬라임을 공격하시겠습니까? 1번: " + s1.name + " 2번: " + s2.name);
			
			if(sel == null || sel.equals("")) {
				System.exit(0);
			}
			
			int selectSlime = Integer.valueOf(sel);
			
			if(selectSlime == 1) {
				s = s1;
			}
			else if(selectSlime == 2) {
				s = s2;
			}
			else {
				JOptionPane.showMessageDialog(null, "올바른 숫자를 입력해주세요.. 제발요");
			}
			
			if(s.hp < 1) {
				System.out.println(s.name + "은 이미 죽어있다");
			}
			else {
				p.attack(s);
				s.attack(p);			
			}
			
			if(s1.hp < 1 && s2.hp < 1) {
				JOptionPane.showMessageDialog(null, "Game Clear!");
				System.exit(0);
			}
			
		} // while
	}

}
