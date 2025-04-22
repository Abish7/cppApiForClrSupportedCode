#include "clsCheck.h"
#include<msclr/marshal.h>
	void clsCheck::tocheck()
	{
		//dllcreation::clstest^ obj = gcnew dllcreation::clstest();
		//obj->txtfilereader("D:\\inage.txt");
		System::Windows::Forms::MessageBox::Show("done");
	}
	void clsCheck::imageread()
	{
		dllcreation::clstest^ obj = gcnew dllcreation::clstest();
		obj->imageReadandSave("D:\\drclt57_backup_28-05\\12-04-2023_13-RadNo_Y12345_W12345_FCAW_Thk14mm_SFD609mm_Exp30sec_ResultResize_input.png", "D:\\check.png");
	}
	void clsCheck::enhancement(std::string inputpath, int doinvert)
	{
		System::String^ a = gcnew System::String(inputpath.c_str());
		System::String^ fname = System::IO::Path::GetFileNameWithoutExtension(a);
		System::IO::FileInfo^ fileinfo = gcnew System::IO::FileInfo(a);
		System::String^ directoryFullPath = fileinfo->DirectoryName;
		if (!System::IO::Directory::Exists(directoryFullPath + "\\output\\"))
		{
			System::IO::Directory::CreateDirectory(directoryFullPath + "\\output\\" );
		}
		
		System::String^ b = gcnew System::String(directoryFullPath + "\\output\\" + fname + ".png");
		System::String^ xml;
		ADRImageProcessor::clsImageProcessor^ imgProcess = gcnew ADRImageProcessor::clsImageProcessor(xml);
		imgProcess->DoEnhancement(a, b, doinvert);	
		//imgProcess->runDemoCRMultilpeImagesDll("D:\\drclt57_backup_28-05\\12-04-2023_15-RadNo_Y12345_W12345_FCAW_Thk14mm_SFD609mm_Exp30sec_ResultResize_input.png");


		//dllcreation::clstest^ obj = gcnew dllcreation::clstest();

		//obj->enhancement(a, b, doinvert);
	}
	void clsCheck::adr(int type, std::string inputImage)
	{
		System::String^ xml;
		System::String^ a = gcnew System::String(inputImage.c_str());
		ADRImageProcessor::clsImageProcessor^ imgProcess = gcnew ADRImageProcessor::clsImageProcessor(xml);
		imgProcess->DoAdr(1, "D:\\drclt57_backup_28-05\\code\\aws\\dllcreattion\\ADRImagineForMDL-DemoWorking-\\Input\\CR\\1-RadNo_Y12345_W12345_FCAW_Thk14mm_SFD609mm_Exp30sec (2) - Copy.png", "D:\\imageqqq.png" ,1);
		//imgProcess->runDemoCRMultilpeImagesDll("D:\\image.png");
	}
//void main()
//{
//	
//	//crow::SimpleApp app;
//	//CROW_ROUTE(app, "/")([]() {
//	//	return "HELLO WORLD";
//	//	});
//	//app.bindaddr("127.0.0.1").port(18080).multithreaded().run();
//}