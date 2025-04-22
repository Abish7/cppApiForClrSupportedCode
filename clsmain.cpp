#include "clsmain.h"
#include <crow.h>

//using namespace crow;
void donemsgbox()
{
	clsCheck obj;
	obj.tocheck();
}
void image()
{
	clsCheck obj;
	obj.imageread();
}
void enhancement(std::string inputpath, int doinvert)
{
	clsCheck obj;
	obj.enhancement(inputpath, doinvert);
}
void adra(int type, std::string inputname)
{
	clsCheck obj;
	obj.adr(type, inputname);
}
void main()
{
	
	crow::SimpleApp app;
	
	CROW_ROUTE(app, "/")([]() {
		return " Home Page !!";
		});
	CROW_ROUTE(app, "/ws/<path>")([](std::string str) {
		donemsgbox();
		return str+" page !!!";
		});
	CROW_ROUTE(app, "/readandsave")([]() {
		image();
		return " Image copy !!";
		});
	CROW_ROUTE(app, "/enhancement/<path>")([](std::string str1) {
		enhancement(str1, 0);
		return " Enhancement !!";
		});
	CROW_ROUTE(app, "/adr")([]() {
		//adra();
		return " ADR !!";
		});
	CROW_ROUTE(app, "/pathToApi/<int>/<path>")
		.methods("GET"_method, "POST"_method, "DELETE"_method)
		([](const crow::request& req, const int& id, std::string name) {
		std::cout << "id : " << id;
		std::cout<<"name : "<<name;
		adra(id, name);
		if (req.method == "GET"_method)
		{
			if ((req.url_params.get("v") != nullptr) & (req.url_params.get("q") != nullptr))
			{
				// ...
			}
			return crow::response(200, "You used GET");
		}
		else if (req.method == "POST"_method)
		{
			return crow::response(200, "You used POST");
		}
		else if (req.method == "DELETE"_method)
		{
			return crow::response(200, "You used DELETE");
		}
		else
		{
			return crow::response(404);
		}
		});
	//CROW_ROUTE(app, "ENDPOINT-ROUTE").methods("POST"_method)([&app, &m_session](const crow::request& req) {
	//	crow::response response("");
	//	response.add_header("Access-Control-Allow-Origin", "*");

	//	return response;
	//	});
	//CROW_ROUTE(app, "/enhancement/<std::string>/<std::string>/<int>")([](std::string a,std::string b, int c) {
	//	enhancement(a, b, c);
	//	return " Enhancement !!";
	//	});
	
	app.bindaddr("127.0.0.1").port(18080).run();
}