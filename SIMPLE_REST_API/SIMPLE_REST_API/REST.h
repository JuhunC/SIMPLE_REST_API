#pragma once
#include"my_header.h"
/// <summary>JuhunC Custom REST API</summary>
namespace REST {
	web::json::value makeRequest(method method_, string append_, json::value const& val, vector<my_header> headers_);
	web::json::value getRequest(std::string append_, json::value const& val);
	web::json::value getRequest(std::string append_, json::value const& val, vector<my_header>& headers_);
	web::json::value postRequest(std::string append_, json::value const& val);
	web::json::value postRequest(std::string append_, json::value const& val, vector<my_header>& headers_);
}
/// <summary>Make Request(GET or POST)</summary>
/// <param name ="method_">HTTP protocol - methods::POST or GET</param>
/// <param name ="append_">Appending Additional URL</param>
/// <param name ="val_">Append Json Data : json::value</param>
/// <param name ="headers_">Append Headers : vector(my_header)</param>
value REST::makeRequest(method method_, string append_, value const& val_, vector<my_header> headers_) {
	http_request req(method_);
	if (headers_.size() > 0) {
		for (my_header hv : headers_) {
			req.headers().add(hv.first(), hv.second());
		}
	}
	req.set_request_uri(util::s2st(append_));
	http_client client(U("http://localhost:8000"));
	http_client_config config;
	
	// add json::value
	if (val_ != NULL)
		req.set_body(val_);

	http_response res = client.request(req).get();
	wcout << client.base_uri().to_string() << util::s2st(append_) << ":" << res.status_code() << endl;

	switch (res.status_code()) {
	case status_codes::OK:
		return res.extract_json().get();
	default:
		std::wcout << L"Failed to connect : " << res.status_code() << std::endl;
		exit(res.status_code());
	}
}
/// <summary>Make GET Request</summary>
/// <param name ="append_">Appending Additional URL</param>
/// <param name ="val_">Append Json Data : json::value</param>
web::json::value REST::getRequest(std::string append_, json::value const& val_) {
	return makeRequest(methods::GET, append_, val_, vector<my_header>());
}
/// <summary>Make GET Request</summary>
/// <param name ="append_">Appending Additional URL</param>
/// <param name ="val">Append Json Data : json::value</param>
/// <param name ="headers_">Append Headers : vector(my_header)</param>
web::json::value REST::getRequest(std::string append_, json::value const& val, vector<my_header>& headers_) {
	return makeRequest(methods::GET, append_, val, headers_);
}
/// <summary>Make POST Request</summary>
/// <param name ="append_">Appending Additional URL</param>
web::json::value REST::postRequest(std::string append_, json::value const& val) {
	return makeRequest(methods::POST, append_, val, vector<my_header>());
}
/// <summary>Make POST Request</summary>
/// <param name ="append_">Appending Additional URL</param>
/// <param name ="val_">Append Json Data : json::value</param>
/// <param name ="headers_">Append Headers : vector(my_header)</param>
web::json::value REST::postRequest(std::string append_, json::value const& val_, vector<my_header>& headers_) {
	return makeRequest(methods::POST, append_, val_, headers_);
}