import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class divisionawt extends Applet implements ActionListener{
	Label l1,l2,l3;
	TextField n1,n2,result;
	Button div;
	String msg;
	
	public void init(){
		l1=new Label("Dividend");
		l2= new Label("Divisor");
		l3=new Label("result");
		n1=new TextField(5);
		n2=new TextField(5);
		div=new Button("Divide");
		div.addActionListener(this);
		add(l1);
		add(n1);
		add(l2);
		add(n2);
		add(div);
		add(l3);
		add(result);
	}
	
	public void actionPerformed(ActionEvent e){
		String arg=e.getActionCommand();
		if (arg.equals("Click")){
			if (this.n1.getText().isEmpty() || this.n2.getText().isEmpty()){
				msg="Enter valid numbers";
				repaint();
			}
			
			else{
				try{
					int num1,num2,num3;
					num1=Integer.parseInt(this.n1.getText());
					num2=Integer.parseInt(this.n2.getText());
					num3=num1/num2;
					result.setText(String.valueOf(num3));
					msg="Division Succesful";
					repaint();
				}
				catch(ArithmeticException ae){
					msg="Can't divide by zero";
					repaint();
				}
				catch(NumberFormatException ne){
					msg="Enter numeric values";
					repaint();
				}
			}
		}
	}
}

/*
<applet code = "divisionawt.class" width="800" height="500">
</applet>
*/
				
				
				
				
				
			
		
	