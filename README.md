# myTutorialCPP

- Здесь можно видеть мое самостоятельное обучение языку с++ с сайтов и курсов:
1. [Сайта](http://grep.cs.msu.ru/cpp.com.ru/index.html),
2. [Курса Сергея Балакирева](https://stepik.org/course/193691/syllabus?auth=login) (у него есть свой сайт),
3. [Еще сайт](http://cppstudio.com/cat/274/)

- В результате были решены задачи. Данный учебный проект направлен не только на решение задач, но и на работу с файловой системой. Архитектура учебного проекта была реализована в соотвествии с принципом "разделяй и властвуй". Мое решение задач отличается от ответов с сайта, я старалась сделать решение универсальным: добавила функции, обработку ошибок, работу с файлом (.log).
- Задачи брались из разных источников, в каждом файле подписано откуда именно:

1. [Задачник МГУ-1](https://al.cs.msu.ru/files/cpp.tasks.2013.pdf)
2. [Задачник МГУ-2](https://al.cs.msu.ru/system/files/CPP_Korukhova.pdf)
3. [Задачи с теорией](https://silvertests.ru/AvailablePartGuide.aspx)
4. [Задачник МГУ-3](https://al.cs.msu.ru/system/files/prac-tasks-Cpp.pdf)
5. [Сайт с задачами МГУ](http://grep.cs.msu.ru/kufas.ru.patched/programming237.htm)
6. [Хорошие задачи с сайта + теория](http://cppstudio.com/cat/285/)
7. [тоже задачи + теория(vpn)](https://purecodecpp.com/archives/433)
8. [codewars](https://www.codewars.com/dashboard)



* Для запуска прогаммы: перейдите в рабочую директорию и выполните следующие шаги
* Для компиляции программы выполнить в командной строке:  `mingw32-make` (windows)
* Для удаления исполняемого файла: `mingw32-make clean` (windows)
* Для Linux вместо `mingw32-make` просто `make`
* Затем запустите исполняемый файл myTasks.exe с указанием определенного типа задач



- Откройте docker desctop
- Собрать докер-образ: `docker build -t my_image .`
- Запустить контейнер: `docker run --rm my_image` 
- Сборка docker-образа осуществлялась в ОС Windows

- Код был написан в VScode (без #include "stdafx.h")
