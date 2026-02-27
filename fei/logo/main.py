from manim import *
import random
import numpy as np

desenho_pontos = [
    230, 231, 232, 233, 255, 254, 253, 275, 275, 276, 277, 299, 298, 297, 319, 320, 321, 343, 342, 341, 340, 318, 296, 274, 252, 230, 
    226, 227, 228, 229, 251, 250, 249, 271, 271, 272, 273, 295, 294, 293, 315, 337, 336, 314, 292, 270, 248, 226, 
    234, 235, 257, 279, 301, 323, 345, 344, 322, 300, 278, 256, 234, 

    203, 181, 159, 160, 182, 181, 182, 204, 
    207, 185, 163, 164, 186, 185, 186, 208, 
    216, 194, 172, 173, 195, 194, 195, 217, 
    200, 178, 156, 179, 158, 180, 202, 
    214, 192, 170, 215, 193, 171, 
    168, 190, 212, 213, 191, 169, 168, 
    205, 183, 161, 162, 184, 183, 206, 
    165, 166, 167, 166, 188, 210, 
]

desenho_arestas = [
    (230, 231), (231, 232), (232, 233), (233, 255), (255, 254), (254, 253), (253, 275), (275, 275), (275, 276), (276, 277), (277, 299), (299, 298), (298, 297), (297, 319), (319, 320), (320, 321), (321, 343), (343, 342), (342, 341), (341, 340), (340, 318), (318, 296), (296, 274), (274, 252), (252, 230), 
    (226, 227), (227, 228), (228, 229), (229, 251), (251, 250), (250, 249), (249, 271), (271, 271), (271, 272), (272, 273), (273, 295), (295, 294), (294, 293), (293, 315), (315, 337), (337, 336), (336, 314), (314, 292), (292, 270), (270, 248), (248, 226), 
    (234, 235), (235, 257), (257, 279), (279, 301), (301, 323), (323, 345), (345, 344), (344, 322), (322, 300), (300, 278), (278, 256), (256, 234), 

    (203, 181), (181, 159), (159, 160), (160, 182), (182, 181), (181, 182), (182, 204), 
    (207, 185), (185, 163), (163, 164), (164, 186), (186, 185), (185, 186), (186, 208), 
    (216, 194), (194, 172), (172, 173), (173, 195), (195, 194), (194, 195), (195, 217), 
    (200, 178), (178, 156), (156, 179), (179, 158), (158, 180), (180, 202), 
    (214, 192), (192, 170), (170, 215), (215, 193), (193, 171), 
    (168, 190), (190, 212), (212, 213), (213, 191), (191, 169), (169, 168), 
    (205, 183), (183, 161), (161, 162), (162, 184), (184, 183), (183, 206), 
    (165, 166), (166, 167), (167, 166), (166, 188), (188, 210), 
]

class Grafo(Scene):
    def construct(self):
        n, m = 23, 22
        alfa = 0.25
        V = list(range(n * m))
        E = []

        # cria arestas aleatorias
        def conecta(a, b):
            if a in desenho_pontos and b in desenho_pontos:
                return

            ai, aj = a // m, a % m
            bi, bj = b // m, b % m
            if (ai >= 7 and ai <= 9 and bi >= 7 and bi <= 9 and aj >= 2 and aj <= m - 2 and bj >= 2 and bj <= m - 2):
                return


            if (a, b) in E or (b, a) in E:
                return

            if (alfa < random.random()):
                return
            
            E.append((a, b))

        movs = [[0, 1], [1, 0], [-1, 0], [0, -1]]
        for i in range(n):
            for j in range(m):
                for [di, dj] in movs:
                    i_, j_ = i + di, j + dj

                    if (i_ < 0 or j_ < 0 or i_ >= n or j_ >= m):
                        continue

                    conecta(i * m + j, i_ * m + j_)

        # adiciona arestas do desenho que faltam
        for e in desenho_arestas:
            a = list(e)

            if (a[0], a[1]) in E or (a[1], a[0]) in E:
                continue

            E.append((a[0], a[1]))

        random.shuffle(E)

        # organiza nodos pra caber no video como grid
        margin = 0.7
        tight = 0.9
        deltax = (config.frame_width / 1.7  - 2*margin) / max(1, m-1) * tight
        deltay = (config.frame_height - 2*margin) / max(1, n-1) * tight

        L = {
            i*m + j: np.array([
                (j - (m-1)/2) * deltax,
                ((n-1)/2 - i) * deltay,
                0.0
            ])
            for i in range(n) for j in range(m)
        }

        g = Graph(
            V, E,
            layout=L,
            vertex_config={"radius": 0.03},
        )

        # anima construcao
        self.add(VGroup(*g.vertices.values()))
        self.play(Create(VGroup(*g.edges.values()), rate_func=linear), run_time=5)

        def edge_mob(a, b):
            return g.edges.get((a, b), g.edges.get((b, a)))

        subset = desenho_arestas
        letras = [edge_mob(a, b) for (a, b) in subset]
        letras = [e for e in letras if e is not None]
        pontos = [g.vertices[p] for p in desenho_pontos]

        self.play(
            *[e.animate.set_stroke(color=DARK_BLUE, width=6) for e in letras],
            *[p.animate.set_fill(DARK_BLUE, opacity=1).set_stroke(DARK_BLUE, width=1) for p in pontos],
            run_time=0.5
        )


        self.play(
            *[e.animate.set_stroke(width=12) for e in letras],
            run_time=0.75
        )

        self.wait()
