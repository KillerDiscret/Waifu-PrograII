//MyForm.cpp
#include "MyForm.h"
using namespace Waifu;
using namespace System::Windows::Forms;
void main()
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
	

}
