//TOLONG CEK LAGI BWANG, AKU PUN GA YAKIIN HEHE//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

// Asumsi: Struktur data untuk User
typedef struct {
    char username[50];
    char password[50];
    char role[20];
    // Tambahkan field lain jika diperlukan (misalnya, ID)
} User;

// Variabel global untuk menyimpan user yang sedang login
User *current_user = NULL;

// Fungsi-fungsi helper (perlu diimplementasikan sesuai kebutuhan)
User* get_user(char username[]);
void clear_current_user();
void update_password(char username[], char password_baru[]);
bool is_user_logged_in();

// Fungsi untuk melakukan Run-Length Encoding
void run_length_encoding(char username[], char encoded_string[]) {
    int count = 1;
    int encoded_index = 0;
    for (int i = 0; username[i]; i++) {
        if (i + 1 < strlen(username) && username[i] == username[i + 1]) {
            count++;
        } else {
            if (count > 1) {
                char count_str[10];
                sprintf(count_str, "%d", count);
                for (int j = 0; count_str[j]; j++) {
                    encoded_string[encoded_index++] = count_str[j];
                }
            }
            encoded_string[encoded_index++] = username[i];
            count = 1;
        }
    }
    encoded_string[encoded_index] = '\0';
}

// F03 - Logout
void logout() {
    if (is_user_logged_in()) {
        clear_current_user();
        printf("Sampai jumpa!\n");
    } else {
        printf("Logout gagal!\n");
        printf("Anda belum login, silahkan login terlebih dahulu sebelum melakukan logout\n");
    }
}

// F04 - Lupa Password
void lupa_password() {
    char username[50];
    char kode_unik[50];

    printf("Username: ");
    scanf("%s", username);
    printf("Kode Unik: ");
    scanf("%s", kode_unik);

    User *user = get_user(username); // Implementasi fungsi get_user sangat penting

    if (user) {
        char expected_kode_unik[100];
        run_length_encoding(username, expected_kode_unik);

        if (strcmp(kode_unik, expected_kode_unik) == 0) {
            printf("Halo %s %s, silakan daftarkan ulang password anda!\n", user->role, username);
            char password_baru[50];
            printf("Password Baru: ");
            scanf("%s", password_baru);
            update_password(username, password_baru); // Implementasi fungsi update_password
            printf("Password berhasil diperbarui!\n");
        } else {
            printf("Kode unik salah!\n");
        }
    } else {
        printf("Username tidak terdaftar!\n");
    }
}

// Fungsi-fungsi berikut HARUS diimplementasikan sesuai dengan struktur data dan kebutuhan program Anda.
User* get_user(char username[]) {
    // Implementasikan fungsi ini untuk mencari user berdasarkan username.
    // Fungsi ini harus mengembalikan pointer ke struct User jika ditemukan, atau NULL jika tidak.
    // Contoh (jika Anda menyimpan user dalam array):
    // for (int i = 0; i < jumlah_user; i++) {
    //     if (strcmp(users[i].username, username) == 0) {
    //         return &users[i];
    //     }
    // }
    return NULL; // User tidak ditemukan
}

void clear_current_user() {
    // Implementasikan fungsi ini untuk menghapus informasi user yang sedang login.
    // Contoh:
    current_user = NULL;
}

void update_password(char username[], char password_baru[]) {
    // Implementasikan fungsi ini untuk mengubah password user.
    // Anda perlu mencari user berdasarkan username dan mengubah passwordnya.
    // Contoh (jika Anda menyimpan user dalam array):
    // for (int i = 0; i < jumlah_user; i++) {
    //     if (strcmp(users[i].username, username) == 0) {
    //         strcpy(users[i].password, password_baru);
    //         return;
    //     }
    // }
}

bool is_user_logged_in() {
    // Implementasikan fungsi ini untuk memeriksa apakah ada user yang sedang login.
    // Contoh:
    return current_user != NULL;
}

int main() {
    // ... Kode inisialisasi dan lainnya ...

    // Contoh Logout
    // Asumsikan ada user yang login
    // Misalnya, setelah login berhasil:
    // current_user = &user_yang_login; // Inisialisasi current_user dengan user yang login

    logout(); // Contoh saat user login
    logout(); // Contoh saat user belum login

    // Contoh Lupa Password
    lupa_password();

    // ... Kode lainnya ...

    return 0;
}
