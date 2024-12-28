# myTutorialCPP

- Здесь можно видеть мое самостоятельное обучение языку с++ с сайтов и курсов:
1. [Сайта](http://grep.cs.msu.ru/cpp.com.ru/index.html),
2. [Курса Сергея Балакирева](https://stepik.org/course/193691/syllabus?auth=login),
3. [Еще сайт](http://cppstudio.com/cat/274/)

- В результате были решены задачи. Данный учебный проект направлен не только на решение задач, но и на работу с файловой системой. Архитектура учебного проекта была реализована в соотвествии с принципом "разделяй и властвуй".
- Задачи брались из разных источников, в каждом файле подписано откуда именно:

[задачник](https://al.cs.msu.ru/files/cpp.tasks.2013.pdf)
[задачник](https://al.cs.msu.ru/system/files/CPP_Korukhova.pdf)
[задачник](https://al.cs.msu.ru/system/files/prac-tasks-Cpp.pdf)
[задачи](http://grep.cs.msu.ru/kufas.ru.patched/programming237.htm)
[тоже задачи](http://cppstudio.com/cat/285/)
[тоже задачи](https://purecodecpp.com/archives/433)
[codewars](https://www.codewars.com/dashboard)


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
