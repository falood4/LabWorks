import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class trafficlights extends Applet implements ItemListener{
  CheckboxGroup grp=new CheckboxGroup();
  Checkbox red, yellow, green;
  Label msg;

  public void init(){
    red=new Checkbox("Red", grp, false);
    yellow=new Checkbox("Yellow", grp, false);
    green=new Checkbox("Green", grp, false);

    msg = new Label(" ");
    red.addItemListener(this);
    yellow.addItemListener(this);
    green.addItemListener(this);

    add(red);
    add(yellow);
    add(green);
    add(msg);
    msg.setFont(new Font("Arial", Font.BOLD, 20));
  }
	
	public void itemStateChanged(ItemEvent ie){
		red.setForeground(Color.BLACK);
		yellow.setForeground(Color.BLACK);
		green.setForeground(Color.BLACK);
		
		if (red.getState()==true){
			red.setForeground(Color.RED);
			msg.setForeground(Color.RED);
			msg.setText("STOP");
		}
		
		if(yellow.getState()==true){
			yellow.setForeground(Color.YELLOW);
			msg.setForeground(Color.YELLOW);
			msg.setText("WAIT");
		}
		
		if(green.getState()==true){
			green.setForeground(Color.GREEN);
			msg.setForeground(Color.GREEN);
			msg.setText("GO");
		}
	}
}


/*
	<applet code = "trafficlights.class" width="800" height="250">
	</applet>
*/