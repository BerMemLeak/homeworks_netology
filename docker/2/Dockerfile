# Используем базовый образ Ubuntu 16.04
FROM ubuntu:16.04

# Устанавливаем необходимые зависимости
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    wget \
    software-properties-common \
    && apt-get clean

# Устанавливаем более новую версию CMake (3.27)
RUN wget https://github.com/Kitware/CMake/releases/download/v3.27.0/cmake-3.27.0-linux-x86_64.sh \
    && chmod +x cmake-3.27.0-linux-x86_64.sh \
    && ./cmake-3.27.0-linux-x86_64.sh --skip-license --prefix=/usr/local \
    && rm cmake-3.27.0-linux-x86_64.sh

# Устанавливаем рабочую директорию внутри контейнера
WORKDIR /app

# Копируем содержимое вашего проекта в рабочую директорию
COPY . .

# Создаем директорию для сборки и переходим в неё
RUN mkdir -p build
WORKDIR /app/build

# Запускаем CMake для генерации Makefile
RUN cmake ..

# Собираем проект
RUN make

# Определяем точку входа в приложение
CMD ["./1"]
