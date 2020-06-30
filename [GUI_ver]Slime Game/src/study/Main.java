package study;

import java.awt.Font;
import java.util.Enumeration;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.UIManager;
import javax.swing.plaf.FontUIResource;

public class Main {

//	static Slime s = null;
	static BlueSlime bs = new BlueSlime("힐링이");
	static RedSlime rs = new RedSlime("강공이");
	static Human h = new Human("용사");
	//라벨 변수 선언, 이미지
	static JLabel lbl, lbl2, imgLbl1, imgLbl2;
	static ImageIcon bsImg, rsImg;
	//버튼
	static JButton btn1, btn2;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
			
		//글꼴 맞추기
		
		Enumeration<Object> keys = UIManager.getDefaults().keys();
		while (keys.hasMoreElements()) {
			Object key = keys.nextElement();
			Object value = UIManager.get(key);
			if (value instanceof FontUIResource)
				UIManager.put(key, new FontUIResource("굴림", Font.PLAIN, 14));
		}
		
		//프레임 생성 및 제목 설정
		JFrame frm = new JFrame();
		frm.setTitle("죽어라 슬라임");

		frm.setSize(350, 350); //프레임 크기 설정
		frm.setLocationRelativeTo(null); // 프레임 화면 가운데 배치
		frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프레임 닫으면 프로그램 종료

		frm.getContentPane().setLayout(null); // 레이아웃 설정
		
		btn1 = new JButton(bs.name); // 버튼1
		btn2 = new JButton(rs.name); // 버튼2

		btn1.setBounds(30,170,122,30); // 버튼 설정
		btn2.setBounds(182,170,122,30);
		
		frm.getContentPane().add(btn1); // 버튼 추가
		frm.getContentPane().add(btn2);
		
		//라벨 1 설정
		lbl = new JLabel();
		lbl.setBounds(30, 210, 274, 50);
		lbl.setHorizontalAlignment(JLabel.CENTER);
		lbl.setText("게임을 시작하겠습니다");
		frm.getContentPane().add(lbl);
		
		//라벨2 설정
		lbl2 = new JLabel();
		lbl2.setBounds(30, 240, 274, 50);
		lbl2.setHorizontalAlignment(JLabel.CENTER);
		lbl2.setText(h.name + "의 체력은 " + h.hp + "입니다.");
		frm.getContentPane().add(lbl2);
		
		imgLbl1 = new JLabel(); //이미지 넣을 라벨 생성

		bsImg = new ImageIcon(Main.class.getResource("/study/img/slime(blue).png"));
		imgLbl1.setIcon(bsImg);
		
		imgLbl1.setBounds(30, 30, 122, 130);
		imgLbl1.setHorizontalAlignment(JLabel.CENTER);
		frm.getContentPane().add(imgLbl1);

		imgLbl2 = new JLabel(); //이미지 넣을 라벨 생성
		rsImg = new ImageIcon(Main.class.getResource("/study/img/slime(red).png"));
		imgLbl2.setIcon(rsImg);
		
		imgLbl2.setBounds(182, 30, 122, 130);
		imgLbl2.setHorizontalAlignment(JLabel.CENTER);
		frm.getContentPane().add(imgLbl2);
		
		//버튼 눌렀을 때
				
		btn1.addActionListener(event -> {
			battle(bs);
		});
		
		btn2.addActionListener(event -> {
		
			battle(rs);
		});
		
		
		frm.setVisible(true);
	}

	private static void battle(Slime s) {
		// TODO Auto-generated method stub
		
		int randomNum = (int) (Math.random() * 3);
		
		if(randomNum == 0) {
			lbl.setText(h.name + "의 공격이 빗나갔다!!");
		}
		else {
			h.attack(s);
		}
		
		if(s instanceof BlueSlime) {
			randomNum = (int) (Math.random() * 3);
			
			if(randomNum == 0) ((BlueSlime) s).heal(s);
			else s.attack(h);
		}
		
		else {
			randomNum = (int) (Math.random() * 3);
			
			if(randomNum == 0) {
				((RedSlime) s).attack2(h);
			}
			else s.attack(h);
		}
		
		if(bs.hp < 1 && rs.hp < 1) {
			JOptionPane.showMessageDialog(lbl2, "Game Clear");
			System.exit(0);
		}
	}

}
