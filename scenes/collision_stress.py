#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Filename: collision_stress.py
# Author:   Lyu Ming <CareF.Lm@gmail.com>

onesp = """
    <sphere material="%s">
        <position x="%.1f" y="%.1f" z="%.1f"/>
        <radius v="0.5"/>
        <body>
            <id i="%d"/>
            <velocity x="%.2f" y="%.2f" z="%.2f"/>
            <mass v="1.0"/>
        </body>
    </sphere>
    """
tot = """
<scene>
    <camera>
        <fov v=".785"/>
        <near_clip v=".01"/>
        <far_clip v="200.0"/>
        <position x="0.0" y="12.0" z="45.0"/>
        <orientation a="0.0" x="0.0" y="-1.0" z="0.0"/>
    </camera>

    <background_color r="0.4" g="0.4" b="0.4"/>

    <refractive_index v="1.0"/>

    <ambient_light r="0.2" g="0.2" b="0.2"/>

    <point_light>
        <position x="1.0" y="3.0" z="12.0"/>
        <color r="1.0" g="1.0" b="1.0"/>
    </point_light>

    <material name="red">
        <ambient r="1.0" g="0.0" b="0.0"/>
        <diffuse r="1.0" g="0.0" b="0.0"/>
        <specular r="0.0" g="0.0" b="0.0"/>
        <refractive_index v="0.0"/>
    </material>

    <material name="sred">
        <ambient r="1.0" g="0.0" b="0.0"/>
        <diffuse r="1.0" g="0.0" b="0.0"/>
        <specular r="1.0" g="1.0" b="1.0"/>
        <refractive_index v="0.0"/>
    </material>

    <material name="green">
        <ambient r="0.0" g="1.0" b="0.0"/>
        <diffuse r="0.0" g="1.0" b="0.0"/>
        <specular r="0.0" g="0.0" b="0.0"/>
        <refractive_index v="0.0"/>
    </material>

    <material name="sgreen">
        <ambient r="0.0" g="1.0" b="0.0"/>
        <diffuse r="0.0" g="1.0" b="0.0"/>
        <specular r="1.0" g="1.0" b="1.0"/>
        <refractive_index v="0.0"/>
    </material>

    <material name="blue">
        <ambient r="0.0" g="0.0" b="1.0"/>
        <diffuse r="0.0" g="0.0" b="1.0"/>
        <specular r="0.0" g="0.0" b="0.0"/>
        <refractive_index v="0.0"/>
    </material>

    <material name="sblue">
        <ambient r="0.0" g="0.0" b="1.0"/>
        <diffuse r="0.0" g="0.0" b="1.0"/>
        <specular r="0.0" g="1.0" b="1.0"/>
        <refractive_index v="0.0"/>
    </material>

%s
    <vertex name="p1" material="red">
        <position x="16.0" y="-4.0" z="-16.0"/>
        <normal x="0.0" y="1.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p2" material="red">
        <position x="-16.0" y="-4.0" z="-16.0"/>
        <normal x="0.0" y="1.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p3" material="red">
        <position x="16.0" y="-4.0" z="16.0"/>
        <normal x="0.0" y="1.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p4" material="red">
        <position x="-16.0" y="-4.0" z="16.0"/>
        <normal x="0.0" y="1.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
    
    <triangle material="red">
        <position x="0.0" y="0.0" z="0.0"/>
        <vertex name="p1"/>
        <vertex name="p2"/>
        <vertex name="p3"/>
        <body>
            <id i="6"/>
        </body>
    </triangle>
    
    <triangle material="red">
        <position x="0.0" y="0.0" z="0.0"/>
        <vertex name="p3"/>
        <vertex name="p2"/>
        <vertex name="p4"/>
        <body>
            <id i="7"/>
        </body>
    </triangle>
    
    <vertex name="p5" material="red">
        <position x="16.0" y="28.0" z="-16.0"/>
        <normal x="0.0" y="-1.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p6" material="red">
        <position x="-16.0" y="28.0" z="-16.0"/>
        <normal x="0.0" y="-1.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p7" material="red">
        <position x="16.0" y="28.0" z="16.0"/>
        <normal x="0.0" y="-1.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p8" material="red">
        <position x="-16.0" y="28.0" z="16.0"/>
        <normal x="0.0" y="-1.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
    
    <triangle material="red">
        <position x="0.0" y="0.0" z="0.0"/>
        <vertex name="p5"/>
        <vertex name="p7"/>
        <vertex name="p6"/>
        <body>
            <id i="8"/>
        </body>
    </triangle>
    
    <triangle material="red">
        <position x="0.0" y="0.0" z="0.0"/>
        <vertex name="p7"/>
        <vertex name="p8"/>
        <vertex name="p6"/>
        <body>
            <id i="9"/>
        </body>
    </triangle>

    <vertex name="p9" material="blue">
        <position x="16.0" y="-4.0" z="-16.0"/>
        <normal x="-1.0" y="0.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p10" material="blue">
        <position x="16.0" y="-4.0" z="16.0"/>
        <normal x="-1.0" y="0.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p11" material="blue">
        <position x="16.0" y="28.0" z="16.0"/>
        <normal x="-1.0" y="0.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p12" material="blue">
        <position x="16.0" y="28.0" z="-16.0"/>
        <normal x="-1.0" y=".0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>

    <triangle material="blue">
        <position x="0.0" y="0.0" z="0.0"/>
        <vertex name="p9"/>
        <vertex name="p10"/>
        <vertex name="p11"/>
        <body>
            <id i="10"/>
        </body>
    </triangle>
    
    <triangle material="blue">
        <position x="0.0" y="0.0" z="0.0"/>
        <vertex name="p11"/>
        <vertex name="p12"/>
        <vertex name="p9"/>
        <body>
            <id i="11"/>
        </body>
    </triangle>
        
    <vertex name="p13" material="blue">
        <position x="-16.0" y="-4.0" z="-16.0"/>
        <normal x="1.0" y="0.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p14" material="blue">
        <position x="-16.0" y="-4.0" z="16.0"/>
        <normal x="1.0" y="0.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p15" material="blue">
        <position x="-16.0" y="28.0" z="16.0"/>
        <normal x="1.0" y="0.0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p16" material="blue">
        <position x="-16.0" y="28.0" z="-16.0"/>
        <normal x="1.0" y=".0" z="0.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>

    <triangle material="blue">
        <position x="0.0" y="0.0" z="0.0"/>
        <vertex name="p13"/>
        <vertex name="p15"/>
        <vertex name="p14"/>
        <body>
            <id i="12"/>
        </body>
    </triangle>
    
    <triangle material="blue">
        <position x="0.0" y="0.0" z="0.0"/>
        <vertex name="p16"/>
        <vertex name="p15"/>
        <vertex name="p13"/>
        <body>
            <id i="13"/>
        </body>
    </triangle>
        
    <vertex name="p17" material="green">
        <position x="-16.0" y="28.0" z="-16.0"/>
        <normal x="0.0" y="0.0" z="1.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p18" material="green">
        <position x="16.0" y="28.0" z="-16.0"/>
        <normal x="0.0" y="0.0" z="1.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p19" material="green">
        <position x="-16.0" y="-4.0" z="-16.0"/>
        <normal x="0.0" y="0.0" z="1.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>
        
    <vertex name="p20" material="green">
        <position x="16.0" y="-4.0" z="-16.0"/>
        <normal x="0.0" y=".0" z="1.0"/>
        <tex_coord u="0.0" v="0.0"/>
    </vertex>

    <triangle material="green">
        <position x="0.0" y="0.0" z="0.0"/>
        <vertex name="p17"/>
        <vertex name="p19"/>
        <vertex name="p18"/>
        <body>
            <id i="14"/>
        </body>
    </triangle>
    
    <triangle material="blue">
        <position x="0.0" y="0.0" z="0.0"/>
        <vertex name="p20"/>
        <vertex name="p18"/>
        <vertex name="p19"/>
        <body>
            <id i="14"/>
        </body>
    </triangle>

    <plane_body>
        <id i="15"/>
        <position x="0.0" y="0.0" z="16.0"/>
        <normal x="0.0" y="0.0" z="-1.0"/>
    </plane_body>
</scene>

"""

color = ["sred", "sgreen", "sblue"]

xmin = -16
xmax = 16
zmin = -16
zmax = 16
ymin = -4
ymax = 28
N = 5

import random
if __name__ == '__main__':
    sps = ""
    with open("collision_more_stress.scene", 'w') as f:
        for nx in range(0, N):
            for ny in range(0,N):
                for nz in range(0,N):
                    vx = 100 * random.random()
                    vy = 100 * random.random()
                    vz = 100 * random.random()
                    rx = (xmin * nx + xmax * (N-nx-1)) / (N-1)
                    ry = (ymin * ny + ymax * (N-ny-1)) / (N-1)
                    rz = (zmin * nz + zmax * (N-nz-1)) / (N-1)
                    sps += onesp%(color[random.randint(0,2)], 
                        rx, ry, rz, 
                        ((nx * N) + ny)*N + nz + 1, 
                        vx, vy, vz)
        f.write(tot%sps)