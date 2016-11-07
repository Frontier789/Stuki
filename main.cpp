#include <Frontier.hpp>

#include <iostream>
using namespace std;

int main()
{
	GuiWindow guiwin(vec2(640,480),"win");
	guiwin.setClearColor(vec4::White);
	// guiwin.setMaxFps(30);
	
	cout << glGetString(GL_VERSION) << endl;
	
	Activity *mainAct = new Activity();
	Layout &layout = mainAct->getLayout();
	
	Font font;
	if (Error e = font.loadFromFile("cour.ttf"))
	{
		cout << e << endl;
		return -1;
	}
	
	guiwin.setRes("defTextFont",&font);
	
	Text *txt = new Text("0");
	txt->setColor(vec4::Black);
	
	layout << txt;
	
	guiwin.pushActivity(mainAct);
	
	return guiwin.run();
}
