int pressed = 0;
#include <fstream>
#include "MyForm.h"
#include "Administrator.h"
#include "Manager.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProjectParking::Administrator form1;
	ProjectParking::Manager form2; 
	ProjectParking::MyForm form;
	Application::Run(% form);
	if (pressed == 2) {
		Application::Run(% form1);
	}
	else if(pressed == 1)
		Application::Run(% form2);
}
