#pragma warning(disable : 4996)
#pragma once
#include"REST.h"

using namespace REST;
using namespace util;

int main(void) {
	vector<my_header> headers;
	json::value token;
	
	token = postRequest("start/temp/0/1", NULL);
	printJsonValue(token);
	
	headers.push_back(my_header(L"X-Auth-Token", token.at(L"token").to_string(), true));
	token = getRequest("oncalls", NULL, headers);
	printJsonValue(token);
	
	json::value action_token;
	headers.push_back(my_header(L"Content-Type", L"application/json",false));
	action_token[L"commands"] = json::value::array();
	action_token[L"commands"][0][L"elevator_id"] = json::value(0);
	action_token[L"commands"][0][L"command"] = json::value(L"STOP");
	printJsonValue(action_token);

	token = postRequest("action", action_token, headers);
	printJsonValue(token);

	token = getRequest("oncalls", NULL, headers);
	printJsonValue(token);

	return 0;
}