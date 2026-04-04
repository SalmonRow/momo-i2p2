#include <stdio.h>
#include <string.h>

typedef struct
{
    int x, y;
} Position;
typedef struct
{
    char type;
    Position pos;
} Piece;
typedef struct
{
    Position start, end;
} Move;
typedef struct
{
    int player_count;
    Piece player[16];
    int opponent_count;
    Piece opponent[16];
    Move moves[2];
} GameState;
typedef struct
{
    int min_steps_to_checkmate;
    Move moves[2];
} SearchResult;

const int QUEEN_DIRS[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const int ROOK_DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int KNIGHT_DIRS[8][2] = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
const int BISHOP_DIRS[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int is_hit(GameState *s, Position k, char b[8][8])
{
    for (int i = 0; i < s->player_count; i++)
    {
        Piece p = s->player[i];
        if (p.type == 'P' || p.type == 'K')
            continue;
        const int (*d)[2] = (p.type == 'Q') ? QUEEN_DIRS : (p.type == 'R') ? ROOK_DIRS
                                                       : (p.type == 'N')   ? KNIGHT_DIRS
                                                                           : BISHOP_DIRS;
        int lim = (p.type == 'Q' || p.type == 'N') ? 8 : 4;
        for (int j = 0; j < lim; j++)
        {
            int nx = p.pos.x, ny = p.pos.y;
            while (1)
            {
                nx += d[j][0];
                ny += d[j][1];
                if (nx < 0 || nx > 7 || ny < 0 || ny > 7)
                    break;
                if (nx == k.x && ny == k.y)
                    return i; // this is when it hit the king
                if (b[nx][ny])
                    break;
                if (p.type == 'N')
                    break;
            }
        }
    }
    return -1;
}

void Check_Checkmate(GameState *s, SearchResult *r)
{
    char b[8][8] = {0};
    for (int i = 0; i < s->player_count; i++)
        b[s->player[i].pos.x][s->player[i].pos.y] = 1;
    Position k = s->opponent[0].pos;
    int hit = is_hit(s, k, b);
    if (hit != -1)
    {
        r->min_steps_to_checkmate = 1;
        r->moves[0] = (Move){s->player[hit].pos, k};
        return;
    }
    b[k.x][k.y] = 1;
    for (int i = 0; i < s->player_count; i++)
    {
        Piece p = s->player[i];
        if (p.type == 'P' || p.type == 'K')
            continue;
        const int (*d)[2] = (p.type == 'Q') ? QUEEN_DIRS : (p.type == 'R') ? ROOK_DIRS
                                                       : (p.type == 'N')   ? KNIGHT_DIRS
                                                                           : BISHOP_DIRS;
        int lim = (p.type == 'Q' || p.type == 'N') ? 8 : 4;
        for (int j = 0; j < lim; j++)
        {
            int nx = p.pos.x, ny = p.pos.y;
            while (1)
            {
                nx += d[j][0];
                ny += d[j][1];
                if (nx < 0 || nx > 7 || ny < 0 || ny > 7 || b[nx][ny])
                    break;
                Position old = s->player[i].pos;
                b[old.x][old.y] = 0;
                b[nx][ny] = 1;
                s->player[i].pos = (Position){nx, ny};
                b[k.x][k.y] = 0;
                int h2 = is_hit(s, k, b);
                if (h2 != -1)
                {
                    r->min_steps_to_checkmate = 2;
                    r->moves[0] = (Move){old, {nx, ny}};
                    r->moves[1] = (Move){s->player[h2].pos, k};
                    return;
                }
                b[k.x][k.y] = 1;
                s->player[i].pos = old;
                b[nx][ny] = 0;
                b[old.x][old.y] = 1;
                if (p.type == 'N')
                    break;
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char type, px, py;
        GameState state;
        SearchResult result;
        result.min_steps_to_checkmate = 3;
        scanf("%d", &state.player_count);
        for (int i = 0; i < state.player_count; i++)
        {
            scanf(" %c %c%c", &type, &px, &py);
            state.player[i] = (Piece){type, {px - 'A', py - '1'}};
        }
        scanf("%d", &state.opponent_count);
        for (int i = 0; i < state.opponent_count; i++)
        {
            scanf(" %c %c%c", &type, &px, &py);
            state.opponent[i] = (Piece){type, {px - 'A', py - '1'}};
        }
        Check_Checkmate(&state, &result);
        if (result.min_steps_to_checkmate == 3)
            printf("None\n");
        else
        {
            printf("%d\n", result.min_steps_to_checkmate);
            for (int i = 0; i < result.min_steps_to_checkmate; i++)
                printf("%c%c %c%c\n", result.moves[i].start.x + 'A', result.moves[i].start.y + '1', result.moves[i].end.x + 'A', result.moves[i].end.y + '1');
        }
    }
    return 0;
}