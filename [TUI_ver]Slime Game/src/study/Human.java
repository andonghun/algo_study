package study;

public class Human {
	
	String name;
	int hp = 100;
	int dmg = 30;
	
	public Human(String n) {
		name = n;
	}
	
	public void attack(Slime s) {
		System.out.println("인간은 " + s.name + "를 공격했다");
		s.hp = s.hp - dmg;
		
		if(s.hp < 1) {
			System.out.println(s.name + "는 사망했다\n");
		}
		else {
			System.out.println("현재 " + s.name + "의 체력은 " + s.hp + "이다\n");		
		}
	}

}
