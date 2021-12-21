#ifndef UBEDOTS_H_
#define UBEDOTS_H_
#include "UbeDotsConfig.h"
#include <winsock2.h>
#include<windows.h>
#include <string>
#include "../curl/curl.h"
/*
 * ATENÇÃO
Crie um arquivo UbeDotsConfig.h contendo as duas linhas abaixo, os valores da url do dipositivo e chave de acesso devem estar entre aspas duplas
#define UBEDOTSURL "UrlDoDispositivo"
#define UBEDOTSTOKEN "Chave de acesso"
*/
#ifndef UBEDOTSCONFIG_H_
#error Crie um arquivo UbeDotsConfig.h seguindo as instruções existentes em ubedots.h
#endif

void UbeDotsAndre(std::string chave, double valor) {
	CURL *hnd;
	struct curl_slist *parametros;
	std::string jsonstr = "{\""+chave+"\":" + std::to_string((valor)) + "}";
	std::string key = std::string("X-Auth-Token: ")+UBEDOTSTOKEN;
	parametros = nullptr;
	parametros = curl_slist_append(parametros, "Content-Type: application/json");
	parametros = curl_slist_append(parametros, key.c_str());
	hnd = curl_easy_init();
	curl_easy_setopt(hnd, CURLOPT_URL, UBEDOTSURL);
	curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
	curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, jsonstr.c_str());
	curl_easy_setopt(hnd, CURLOPT_USERAGENT, "curl/7.38.0");
	curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, parametros);
	curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
	curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
	curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
	FILE *devnull = fopen("lixo", "w");
	curl_easy_setopt(hnd, CURLOPT_WRITEDATA, devnull);
	curl_easy_perform(hnd);
	curl_easy_cleanup(hnd);
	fclose(devnull);
	hnd = nullptr;
	curl_slist_free_all(parametros);
	parametros = nullptr;
}



#endif /* UBEDOTS_H_ */
