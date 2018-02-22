include("core/input")
include("core/entity")
include("player")
local obj0 = Entity("box.jpg", "box 1")
local obj1 = Entity("box.jpg", "yayyy you will never find me")
local obj2 = Entity("box.jpg", "really common name")
local obj3 = Entity("wall.png", "level1_box_23")
local player = Player()

player.set_scale(2,2,1)


local x = 0
local dx = 3

function update(dt)
   for _,e in pairs(entities) do
      e.update(dt)
   end
end

