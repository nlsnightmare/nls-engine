include("core/input")
entities = {}



function find_entity(filter)
   if type(filter) == "string" then
      for _,e in pairs(entities) do
	 if e.get_name() == filter then
	    return e
	 end
      end
   end
   for _,e in pairs(entities) do
      if e.id == filter then
	 return e
      end
   end
end



function Entity(img, n1)
   local self = {}
   self.to_be_deleted = false;

   entities[#entities + 1] = self
   self.ptr = new_entity(img,n1)
   self.id = entity_get_id(self.ptr)

   self.position = {
      x = 0,
      y = 0,
      z = 0
   }

   self.scale = {
      x = 1,
      y = 1,
      z = 1
   }
   


   function self.get_pos()
      self.position.x,self.position.y,self.position.z = entity_get_position(self.ptr)
      return self.position.x,self.position.y,self.position.z
   end

   function self.get_name()
      return entity_get_name(self.ptr)
   end

   function self.set_pos(x,y,z)
      entity_set_position(self.ptr, x,y,z)
      self.position.x = x
      self.position.y = y
      self.position.z = z
   end

   function self.translate(dx,dy,dz)
      entity_translate(self.ptr, dx,dy,dz)
      self.position.x = self.position.x + dx
      self.position.y = self.position.y + dy
      self.position.z = self.position.z + dz
   end

   function self.get_pos()
      self.position.x,self.position.y,self.position.z = entity_get_position(self.ptr)
      return self.position
   end
   
   function self.get_scale()
      self.scale.x,self.scale.y,self.scale.z = entity_get_scale(self.ptr)
      return self.scale
   end
   function self.set_scale(x,y,z)
      entity_set_scale(self.ptr, x,y,z)
      self.scale.x = x
      self.scale.y = y
      self.scale.z = z
   end
   

   function self.update(dt)
      if get_key(keys.W) then
	 self.translate(1*dt,0,0)
      end

   end


   function self.destroy()
      entity_delete(self.ptr)
      for i= 1,#entities do
	 if entities[i] == self then
	    entities[i] = nil
	    break
	 end

      end
      
   end
   

   function self.get_mass()
      return entity_get_mass(self.ptr)
   end

   function self.set_mass(v)
      entity_set_mass(self.ptr,v)
   end

   function self.set_trigger(v)
      entity_set_trigger(self.ptr, v)
   end
   
	 

   function self.on_collision(other,data)
   end
   function self.on_trigger(other,data)
   end
   
   
   return self
end
