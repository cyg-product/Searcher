#include <stdbool.h>
#include <stdio.h>

typedef struct SearchPortal {
    bool has_mainpage;          // 메인페이지(홈)
    bool has_search_result;     // 검색 결과 페이지
    bool has_image_search;      // 이미지 검색
    bool has_video_search;      // 동영상 검색
    bool has_news_search;       // 뉴스 검색
    bool has_login;             // 로그인/회원가입 기능
    bool has_extra_services;    // 번역/지도/쇼핑 등 기타 서비스
} SearchPortal;

int main(void) {
    SearchPortal portal = {
        .has_mainpage = true,
        .has_search_result = true,
        .has_image_search = false,
        .has_video_search = false,
        .has_news_search = false,
        .has_login = false,
        .has_extra_services = false
    };

    printf("SearchPortal 구성:\n");
    printf("  메인페이지: %s\n", portal.has_mainpage ? "있음" : "없음");
    printf("  검색 결과 페이지: %s\n", portal.has_search_result ? "있음" : "없음");
    printf("  이미지 검색: %s\n", portal.has_image_search ? "있음" : "없음");
    printf("  동영상 검색: %s\n", portal.has_video_search ? "있음" : "없음");
    printf("  뉴스 검색: %s\n", portal.has_news_search ? "있음" : "없음");
    printf("  로그인 기능: %s\n", portal.has_login ? "있음" : "없음");
    printf("  기타 서비스: %s\n", portal.has_extra_services ? "있음" : "없음");

    return 0;
}
