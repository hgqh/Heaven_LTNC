# HEAVEN PONG
- Thử nghiệm game: 

# Giới thiệu game

SPECIAL PONG là một game thuộc thể loại Pong. Trong trò chơi này, bạn sẽ tham gia vào các trận đấu bóng với chế độ 1 PLAYER hoặc 2 PLAYER. Mục tiêu của trò chơi là điều khiển thanh chắn để đỡ bóng và ghi điểm bằng cách làm cho bóng nảy qua đối phương. Trò chơi cung cấp hai cấp độ khó: EASY và HARD, với các bản đồ và thử thách khác nhau. Đạt được 5 điểm trước sẽ giúp bạn giành chiến thắng.

- [0. Cách tải game](#0-cách-tải-game)
    * [a. Cách 1: Không bao gồm code.](#a-cách-1-không-bao-gồm-code)
    * [b. Cách 2: Bao gồm code và có thể biên dịch.](#b-cách-2-bao-gồm-code-và-có-thể-biên-dịch)
- [1. Bắt đầu game](#1bắt-đầu-game)
- [2. Chọn level](#2chọn-level)
- [3. Các thành phần trong game:](#3-các-thành-phần-trong-game)
- [4. Cách chơi](#4-cách-chơi)
    * [a. Các loại cây](#acác-loại-cây)
    * [b. Các loại zombie](#bcác-loại-zombie)
- [5. Chiến thắng và thất bại](#5-chiến-thắng-và-thất-bại)
- [Về đồ họa của game:](#về-đồ-họa-của-game)
- [Về source code game](#về-source-code-game)

# 0. Cách tải game

## a. Cách 1: Chơi game từ bản nén sẵn

### Windows:

- Tải game:
   - Tải tệp `.zip` từ link [Heaven Pong - Releases](https://github.com/hgqh/Heaven_LTNC/releases/tag/v1.0).
   - Hoặc tải `.tar.gz` nếu cần.
- Giải nén:
   - Giải nén tệp `.zip` hoặc `.tar.gz` vào một thư mục trên máy tính của bạn.
- Chạy game:
   - Sau khi giải nén, mở thư mục chứa trò chơi và tìm file `Heaven_LTNC.exe`.
   - Nhấp đúp chuột vào `Heaven_LTNC.exe` để khởi chạy trò chơi.

### Linux/MacOS:
- Tải game:
   - Tương tự như Windows, tải `.zip` hoặc `.tar.gz` từ link trên.
- Giải nén:
   - Giải nén tệp `.zip` hoặc `.tar.gz` vào một thư mục bất kỳ.
- Chạy game:
   - Mở Terminal.
   - Chuyển đến thư mục chứa trò chơi bằng lệnh `cd` (ví dụ: `cd ~/Downloads/Heaven_LTNC_v1.0/`).
   - Gõ lệnh sau để chạy game:
     ```bash
     ./Heaven_LTNC
     ```
   - **Lưu ý:** Bạn cần phải cấp quyền thực thi cho tệp `Heaven_LTNC` bằng cách gõ lệnh sau trước khi chạy:
     ```bash
     chmod +x Heaven_LTNC
     ```

---

## b. Cách 2: Tải repo về và tự biên dịch

### Windows:

- Clone repo về máy:
   - Mở Terminal hoặc Git Bash, sau đó chạy lệnh sau để clone repo:
     ```bash
     git clone https://github.com/hgqh/Heaven_LTNC.git
     ```
   - Hoặc bạn có thể tải `.zip` chứa mã nguồn từ GitHub và giải nén.
- Cài MinGW:
   - Tải và cài đặt MinGW-W64 phiên bản `GCC-8.1.0 x86_64-posix-seh` từ [MinGW-W64](https://sourceforge.net/projects/mingw-w64/).
   - Sau khi cài đặt, thêm đường dẫn của MinGW vào biến môi trường `PATH` của hệ thống.

- Cài đặt GNU Make:
   - Tải GNU Make từ [GNUWin32](http://gnuwin32.sourceforge.net/packages/make.htm) hoặc sử dụng MinGW để cài đặt GNU Make.
   - Sau khi cài đặt, thêm đường dẫn của GNU Make vào biến môi trường `PATH`.
- Biên dịch trò chơi:
   - Mở `cmd` hoặc Git Bash và di chuyển đến thư mục chứa `Makefile`.
   - Gõ lệnh `make` để biên dịch trò chơi:
     ```bash
     make
     ```
- Chạy game:
   - Sau khi biên dịch, bạn sẽ có file thực thi trong thư mục `bin`. Chạy file thực thi đó để chơi game.

### Linux/MacOS:
- Clone repo về máy:
   - Mở Terminal và chạy lệnh sau để clone repo:
     ```bash
     git clone https://github.com/hgqh/Heaven_LTNC.git
     ```
   - Hoặc tải `.zip` chứa mã nguồn từ GitHub và giải nén.
- Cài đặt GCC và các thư viện cần thiết:
   - Trên Ubuntu/Debian:
     ```bash
     sudo apt update
     sudo apt install g++ libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev make
     ```
   - Trên macOS sử dụng Homebrew:
     ```bash
     brew install sdl2 sdl2_image sdl2_mixer sdl2_ttf make
     ```
- Biên dịch trò chơi:
   - Mở Terminal và chuyển đến thư mục chứa `Makefile`.
   - Chạy lệnh sau để biên dịch trò chơi:
     ```bash
     make
     ```
- Chạy game:
   - Sau khi biên dịch, chạy tệp thực thi từ thư mục `bin` bằng lệnh:
     ```bash
     ./bin/Heaven_LTNC
     ```

**Một số chú ý:**

- **Windows:** Khi biên dịch trên Windows, cần phải xóa các tệp `libgcc_s_seh-1.dll`, `libstdc++-6.dll`, và `libwinpthread-1.dll` nếu chúng xuất hiện trong thư mục chứa `Heaven_LTNC.exe`.
- **Linux/MacOS:** Khi biên dịch trên Linux/MacOS, đảm bảo rằng bạn đã cài đặt đầy đủ các thư viện SDL2 trước khi biên dịch.

# 1. Bắt đầu game