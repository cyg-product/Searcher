#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_LINE_LENGTH 1024

// 파일 하나를 열어 키워드를 검색하는 함수
void search_file(const char* filepath, const char* keyword) {
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        // 파일을 열 수 없을 경우 에러 메시지 출력
        perror("파일 열기 실패");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    // 파일을 한 줄씩 읽으며 키워드 검색
    while (fgets(line, sizeof(line), file) != NULL) {
        // strstr 함수는 문자열에서 특정 부분 문자열을 찾는다.
        if (strstr(line, keyword) != NULL) {
            printf("키워드 '%s'가 파일 '%s'에서 발견되었습니다.\n", keyword, filepath);
            found = 1;
            break; // 찾았으면 더 이상 읽지 않고 함수 종료
        }
    }

    fclose(file);
}

// 특정 디렉토리 내의 모든 파일을 검색하는 함수
void search_directory(const char* dirname, const char* keyword) {
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        perror("디렉토리 열기 실패");
        return;
    }

    struct dirent* entry;

    // 디렉토리 내의 엔트리들을 하나씩 읽음
    while ((entry = readdir(dir)) != NULL) {
        // 현재 디렉토리(.)와 상위 디렉토리(..)는 건너뜀
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // 파일 경로를 생성
        char filepath[1024];
        snprintf(filepath, sizeof(filepath), "%s/%s", dirname, entry->d_name);

        // 만약 엔트리가 일반 파일이라면 검색 함수 호출
        if (entry->d_type == DT_REG) {
            search_file(filepath, keyword);
        }
    }

    closedir(dir);
}

// 메인 함수
int main(int argc, char* argv[]) {
    // 사용법: ./search [디렉토리] [키워드]
    if (argc != 3) {
        fprintf(stderr, "사용법: %s <디렉토리 경로> <검색 키워드>\n", argv[0]);
        return 1;
    }

    const char* dirname = argv[1];
    const char* keyword = argv[2];

    printf("디렉토리 '%s'에서 키워드 '%s'를 검색합니다...\n", dirname, keyword);
    search_directory(dirname, keyword);

    return 0;
}
