# Используем базовый образ с поддержкой MinGW-w64
FROM ubuntu:20.04

# Устанавливаем MinGW-w64 и make
RUN apt-get update && apt-get install -y \
    mingw-w64 \
    make \
    g++ \
    gcc
WORKDIR /app
COPY . .
RUN mingw32-make
CMD ["./myPeople"]
